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
 *  Modified by Zuoguoqing, 2014/09/23
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "linktable.h"
#include "menu.h"

/*Record the head of LinkTable*/
static tLinkTable* _HEAD_ = NULL;

/*Cmd handler method*/
int Help()
{
    ShowCmdList(_HEAD_);
    return 0;
}

int Quit()
{
    if(_HEAD_ != NULL)
    {
        DelLinkTable(&_HEAD_);
    }
    exit(0);
    return 0;
}

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
	node->des = "Version of menu is V3.0\n";
	node->handler = NULL;
	AddLinkTableNode(*list, node);

	node = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));
	node->cmd = "quit";
	node->des = "Quit from program Menu V3.0\n";
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

/*Method to creat a new help command*/
tLinkTableNode* CreatCmd(char* cmd, char* des, int (*handler)())
{
    tLinkTableNode* node = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));
    node->next = NULL;
    node->cmd = cmd;
    node->des = des;
    node->handler = handler;
    
    return node;
}

/*Method to add new command to command list*/
tLinkTable* AddCmd(tLinkTable** link, tLinkTableNode* node)
{
    if(*link == NULL)
    {
        *link = CreatLinkTable();
    }
    
    if(!node)
    {
        return NULL;
    }
    
    if(FindMenuCmd(*link, node->cmd))
    {
        printf("Failure! Name of this cmd has be already exit! Please rename it!\n");
        return NULL;
    }
    
    if(AddLinkTableNode(*link, node))
    {
        return *link;
    }
    else
    {
        return NULL;
    }
}

/*Method to delete a command from command list*/
int DelCmd(tLinkTable* link, const char* cmd)
{
    if(!link || !(link->head))
    {
        return 0;
    }
    tLinkTableNode* tmp = FindMenuCmd(link, cmd);
    if(!tmp)
    {
        printf("\nNo such command in command list!\n");
        return 0;
    }
    
    if(DelLinkTableNode(link, tmp))
    {
        return 1;
    }
    
    return 0;
}

/*Method to delete command menu*/
int DelCmdMenu(tLinkTable** link)
{
    if(!link || !(*link))
    {
        return 0;
    }
    
    if(!DelLinkTable(link))
    {
        return 0;
    }
    return 1;
}


