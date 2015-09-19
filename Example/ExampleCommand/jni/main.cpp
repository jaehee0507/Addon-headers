#include <dlfcn.h>
#include <jni.h>
#include <string>
#include <android/log.h>
#include "mcpelauncher.h"

#include "mcpe/client/MinecraftClient.h"
#include "mcpe/command/ServerCommandParser.h"
#include "mcpe/util/Token.h"

using namespace std;

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "affoaddon", __VA_ARGS__)

string commandFunc(vector<Token> const& args) {
    /**
     * index 0 - sender nickname
     * index 1 - 1st argument
     * index n - nth argument
     */
    string arg1 = args[1].getText("");
    
    return "Your Text : "+arg1;
}

void (*mc_setup)(Minecraft*, ServerCommandParser&);
void mc_setup_hook(Minecraft* thiz, ServerCommandParser& parser) {
    /**
     * Symbols
     * s - string
     * n - number
     */
    parser.addCommand("example", "s", commandFunc);
    
    mc_setup(thiz, parser);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    
    mcpelauncher_hook((void*) &Minecraft::setupCommandParser, (void*) &mc_setup_hook, (void**) &mc_setup);
    
	return JNI_VERSION_1_2;
}
