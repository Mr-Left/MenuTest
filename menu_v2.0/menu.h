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
 *	Created by Zuoguoqing, 2014/09/20
 *
 */
 
#ifndef _MENU_H
#define _MENU_H


/*Record the head of LinkTable*/
static tLinkTable* _HEAD_ = NULL;

/*Method to initialize linklist*/
void InitMenu(tLinkTable**);

/*Method to show all cmd list member*/
void ShowCmdList(const tLinkTable*);

/*Method to find weather there is a cmd like input*/
tLinkTableNode* FindMenuCmd(const tLinkTable*, const char*);

/*Cmd handler method*/
int Help();

int Quit();

#endif

