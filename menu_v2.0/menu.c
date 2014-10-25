/**************************************************************************************************/
/* Copyright (C) SA14226202@USTC, 2014-2015                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Zuoguoqinng                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  Definition of menu                                                   */
/**************************************************************************************************/

/*
 *	Revision log
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "linktable.h"
#include "menu.h"

/*Method to initialize linklist*/
void InitMenu(tLinkTable** list)
{
    if(*list == NULL)
    {
	    *list = CreatLinkTable();
	}
	_HEAD_ = *list;
	tLinkTableNode* node = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));

	node->cmd = "help";
	node->des = "Menu list: \n";
	node->handler = Help;
	AddLinkTableNode(*list, node);

	node = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));
	node->cmd = "version";
	node->des = "Version of menu is V2.0\n";
	node->handler = NULL;
	AddLinkTableNode(*list, node);

	node = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));
	node->cmd = "quit";
	node->des = "Quit from program Menu V2.0\n";
	node->handler = Quit;
	AddLinkTableNode(*list, node);
}

/*Method to show all cmd list member*/
void ShowCmdList(const tLinkTable* list)
{
	tLinkTableNode* tmp = list->head;
	printf("COMMAND\t\t\tDESCRIPTION\n\n");
	while(tmp)
	{
		printf("%s\t\t\t%s", tmp->cmd, tmp->des);
		tmp = tmp->next;
	}
}

/*Method to find weather there is a cmd like input*/
tLinkTableNode* FindMenuCmd(const tLinkTable* list, const char* cmd)
{
	tLinkTableNode* tmp = list->head;
	while(tmp)
	{
		if(!strcmp(tmp->cmd, cmd))
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	
	return NULL;
}

/*Cmd handler method*/
int Help()
{
    ShowCmdList(_HEAD_);
    return 0;
}

int Quit()
{
    exit(0);
    return 0;
}

