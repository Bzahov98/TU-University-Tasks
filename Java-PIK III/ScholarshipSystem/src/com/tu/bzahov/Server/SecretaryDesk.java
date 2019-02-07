package com.tu.bzahov.Server;

import com.tu.bzahov.Model.Document;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
//DONE:
public class SecretaryDesk {
    private static Queue<Document> waitQueue  = new LinkedList<>();
    private static List <Document> acceptedList = new ArrayList<>();
    private static List <Document> blockedList = new ArrayList<>();

    public static synchronized Document getDocument(){
        if (waitQueue.size() != 0){
            return waitQueue.remove();
        }else return null;
    }

    public static synchronized void addWaitQueueDocument(Document doc){
        if (doc!= null){
            System.out.println("added to wait Queue document of "+ doc.getName());
            waitQueue.add(doc);
        }
    }

    public static synchronized void addAcceptDocument(Document doc){
        if (doc!= null){
            System.out.println("added Accepted document of "+ doc.getName());
            acceptedList.add(doc);
        }
    }
    public static synchronized void addBlockedDocument(Document doc){
        if (doc!= null){
            System.out.println("added Blocked document of "+ doc.getName());
            blockedList.add(doc);
        }
    }
}
