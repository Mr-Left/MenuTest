/**************************************************************************************************/
/* Copyright (C) SA14226202@USTC, 2014-2015                                                       */
/*                                                                                                */
/*  FILE NAME             :  linktable.h                                                          */
/*  PRINCIPAL AUTHOR      :  Zuoguoqinng                                                          */
/*  SUBSYSTEM NAME        :  LinkTable                                                            */
/*  MODULE NAME           :  LinkTable                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  Headers of LinkTable                                                 */
/**************************************************************************************************/

/*
 *	Revision log
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */

#ifndef _LINK_TABLE_H
#define _LINK_TABLE_H

/*Definition of LinkTableNode*/
typedef struct LinkTableNode
{
    struct LinkTableNode* next;
    char* cmd;
    char* des;
    int (*handler)();
} tLinkTableNode;

/*Definition of LinkTable*/
typedef struct LinkTable
{
    tLinkTableNode* head;
    tLinkTableNode* tail;
    int node_sum;
} tLinkTable;

/*Method to creat a LinkTable*/
tLinkTable* CreatLinkTable();

/*Method to add node to LinkTable,return 0 means failure and return 1 means success*/
int AddLinkTableNode(tLinkTable*, tLinkTableNode*);

/*  Method to delete node from LinkTable,return 0 means failure and return 1 means success*/
int DelLinkTableNode(tLinkTable* link, tLinkTableNode* node);

/*Method to find privous node*/
tLinkTableNode* FindPreNode(const tLinkTable* link, const tLinkTableNode* node);

/*Method to delete LinkTable*/
int DelLinkTable(tLinkTable*);

#endif
 
