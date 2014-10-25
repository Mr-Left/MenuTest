/**************************************************************************************************/
/* Copyright (C) SA14226202@USTC, 2014-2015                                                       */
/*                                                                                                */
/*  FILE NAME             :  linkTable.c                                                          */
/*  PRINCIPAL AUTHOR      :  Zuoguoqinng                                                          */
/*  SUBSYSTEM NAME        :  linkTable                                                            */
/*  MODULE NAME           :  linkTable                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  Definition of link table                                             */
/**************************************************************************************************/

/*
 *	Revision log
 *
 *	Created by Zuoguoqing, 2014/09/20
 *
 */

#include <stdlib.h>
#include "linktable.h"

/*Method to creat a LinkTable*/
 tLinkTable* CreatLinkTable()
 {  
    tLinkTable* link = (tLinkTable*)malloc(sizeof(tLinkTable));
    link->head = NULL;
    link->tail = NULL;
    link->node_sum = 0;
    
    return link;
 }


/*Method to add node to LinkTable,return 0 means failure and return 1 means success*/
int AddLinkTableNode(tLinkTable* link, tLinkTableNode* node)
{
    if(!node)
    {
        return 0;
    }
    if(!link)
    {
        return 0;
    }
    node->next = NULL;
    link->node_sum++;
    if(link->head == NULL)
    {
        link->head = node;
        link->tail = node;
    }
    else
    {
        link->tail->next = node;
        link->tail = node;
    }
    
    return 1;
}

/*  Method to delete node from LinkTable,return 0 means failure and return 1 means success*/
int DelLinkTableNode(tLinkTable* link, tLinkTableNode* node)
{
    if(!node)
    {
        return 0;
    }
    if(!link)
    {
        return 0;
    }
    if(link->head == NULL)
    {
        return 0;
    }
    tLinkTableNode* pre = FindPreNode(link, node);
    if(!pre)
    {
        link->head = NULL;
        link->tail = NULL;
    }
    pre->next = node->next;
    if(link->tail == node)
    {
        link->tail = pre;
    }
    free(node);
    
    return 1;
}

/*Method to find privous node*/
tLinkTableNode* FindPreNode(const tLinkTable* link, const tLinkTableNode* node)
{
    if(!link || link->head ==NULL || link->head == node)
    {
        return NULL;
    }
    tLinkTableNode* pre = link->head;
    while(pre->next != node)
    {
        pre = pre->next;
    }
    
    return pre;
}

/*Method to delete LinkTable*/
int DelLinkTable(tLinkTable* link)
{
    if(!link || link->head == NULL)
    {
        return 0;
    }
    tLinkTableNode* tmp = link->head;
    while(link->head)
    {
        link->head = link->head->next;
        free(tmp);
        tmp = link->head;
    }
    
    return 1;
}

