/**************************************************************************************************/
/* Copyright (C) SA14226202@USTC, 2014-2015                                                       */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  Zuoguoqinng                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  Headers of menu                                                      */
/**************************************************************************************************/

/*
 *	Revision log
 *  
 *  Modified by Zuoguoqing, 2014/09/23
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */
 
#ifndef _MENU_H
#define _MENU_H

/*Method to initialize linklist*/
void InitMenu(tLinkTable** link);

/*Method to show all cmd list member*/
void ShowCmdList(const tLinkTable* link);

/*Method to find weather there is a cmd like input*/
tLinkTableNode* FindMenuCmd(const tLinkTable* link, const char* cmd);

/*Method to creat a new help command*/
tLinkTableNode* CreatCmd(char* cmd, char* des, int (*handler)());

/*Method to add new command to command list*/
tLinkTable* AddCmd(tLinkTable** link, tLinkTableNode* node);

/*Method to delete a command from command list*/
int DelCmd(tLinkTable* link, const char* cmd);

/*Method to delete command menu*/
int DelCmdMenu(tLinkTable** link);

#endif

