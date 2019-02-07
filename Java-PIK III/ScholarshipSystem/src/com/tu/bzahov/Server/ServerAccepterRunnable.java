package com.tu.bzahov.Server;

import com.tu.bzahov.Model.Document;
import com.tu.bzahov.Model.Message;

import java.io.*;
import java.net.Socket;

public class ServerAccepterRunnable implements Runnable {

    public static final String STUDENT_TYPE = "student";
    public static final String SECRETARY_TYPE = "secretary";
    Socket socket;
    ObjectInputStream objectInputStream;
    ObjectOutputStream objectOutputStream;

    public ServerAccepterRunnable(Socket socket) {
        this.socket = socket;
        try {
            this.objectInputStream = new ObjectInputStream(socket.getInputStream());
            this.objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {

        System.out.println("on ServerAccepterRunnable" );

        try {
            Message type = (Message) objectInputStream.readObject();
                switch (type.getMessage()){
                    case STUDENT_TYPE:
                        tryAcceptStudent();
                        break;
                    case SECRETARY_TYPE:
                        tryAcceptSecretary();
                        break;
                    default:
                        System.err.println("Error in task type");
                        break;
                }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void tryAcceptStudent() throws IOException, ClassNotFoundException {
        Document doc = (Document) objectInputStream.readObject();
        SecretaryDesk.addWaitQueueDocument(doc);
        System.out.println("sent doc to Wait Queue");
    }

    private void tryAcceptSecretary() throws IOException, ClassNotFoundException {
        while (true){
            objectOutputStream.writeObject(SecretaryDesk.getDocument());
            Document doc = (Document) objectInputStream.readObject();
            if (doc== null){
                return;
            }

            if (doc.isValid()){
                SecretaryDesk.addAcceptDocument(doc);
            }else{
                SecretaryDesk.addBlockedDocument(doc);
            }
        }
    }

    @Deprecated
    private int requestAccess(DataInputStream inputStream, DataOutputStream outputStream) {
        try {
            outputStream.writeUTF("operation number");
            
        } catch (IOException e) {
            e.printStackTrace();
        }
        return 0;
    }


    @Deprecated
    public ServerAccepterRunnable(Socket socket, DataInputStream inputStream, DataOutputStream outputStream) {
        this.socket = socket;
        this.inputStream = inputStream;
        this.outputStream = outputStream;
    }
    @Deprecated
    DataInputStream inputStream;
    @Deprecated
    DataOutputStream outputStream;

}
