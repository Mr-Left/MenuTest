/**************************************************************************************************/
/* Copyright (C) SA14226202@USTC, 2014-2015                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu_test.c                                                          */
/*  PRINCIPAL AUTHOR      :  Zuoguoqinng                                                          */
/*  SUBSYSTEM NAME        :  menu_test                                                            */
/*  MODULE NAME           :  menu_test                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a test of menu program                                       */
/**************************************************************************************************/

/*
 *	Revision log
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */
 
 #include <stdio.h>
 
 #include "linktable.h"
 #include "menu.h"
 
 #define CMD_MAX_LEN 20
 
 int main()
 {
    tLinkTable* link_table = NULL;
    char cmd[CMD_MAX_LEN];
    
    InitMenu(&link_table);
    while(1)
    {
        printf("Please input a cmd >");
        scanf("%s", cmd);
        tLinkTableNode* tmp = FindMenuCmd(link_table, cmd);
        if(!tmp)
        {
            printf("Can not find this cmd,please input again or input 'help' to get some infomation\n");
            continue;
        }
        printf("%s\t\t\t%s", tmp->cmd, tmp->des);
        if(tmp->handler != NULL)
        {
            tmp->handler();
        }       
    }
    
    return 0;
 }
