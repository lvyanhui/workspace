#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "zkteco_id100com_jni_id100sdk.h"
#include "termb.h"
int
main()
{
    int ret = 0;
    char samid[40] = {0};

    if (InitCommExt() == 0) {
        fprintf(stderr, "port init failed\n");
        exit(-1);
    }
    if (GetSAMStatus() != 1) {
        fprintf(stderr, "GetSAMStatus failed\n");
        exit(-1);
    }
    if (GetSAMID(samid) != 1) {
        fprintf(stderr, "GetSAMID failed\n");
        exit(-1);       
    } else {
        printf("SAMID: %s\n", samid);
    }

    if (Authenticate() == 1) {
        fprintf(stderr, "Authenticate success\n");
        ret = Read_Content(1);
        if (ret == 1) {
            fprintf(stderr, "Read_Content success\n");
        } else {
            fprintf(stderr, "Error happened: %d\n", ret);
        }
    } else {
        fprintf(stderr, "please put card correctly\n");
        exit(-1);
    }
    if (CloseComm() != 1) {
        fprintf(stderr, "CloseComm: failed");
    }
}


