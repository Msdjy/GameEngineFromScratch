#include <stdio.h>
#include<iostream>
using namespace std;
#include "IApplication.hpp"

using namespace My;

namespace My {
        extern IApplication* g_pApp;
}

int main(int argc, char** argv) {
        int ret;

        if ((ret = g_pApp->Initialize()) != 0) {
                printf("App Initialize failed, will exit now.");
                return ret;
        }

        while (!g_pApp->IsQuit()) {
                g_pApp->Tick();
        }

        g_pApp->Finalize();
        cout<<1<<endl;
        return 0;
}