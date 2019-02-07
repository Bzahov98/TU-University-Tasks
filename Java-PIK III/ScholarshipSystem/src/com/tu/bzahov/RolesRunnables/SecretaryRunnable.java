package com.tu.bzahov.RolesRunnables;

import com.tu.bzahov.Model.Document;
import com.tu.bzahov.Model.Message;
import com.tu.bzahov.Server.ServerAccepterRunnable;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class SecretaryRunnable implements Runnable{
    private int id;
    private Socket socket;
    private ObjectInputStream objectSocketInput;
    private ObjectOutputStream objectSocketOutput;


    public SecretaryRunnable(Socket socket) {
        this.socket = socket;
        try {
//            socketInput = new Scanner(socket.getInputStream());
//            socketOutput = new PrintStream(socket.getOutputStream());
            objectSocketOutput = new ObjectOutputStream(socket.getOutputStream());
            objectSocketInput = new ObjectInputStream(socket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    @Override
    public void run() {
        try {
            objectSocketOutput.writeObject(new Message(ServerAccepterRunnable.SECRETARY_TYPE));
            while (true){
                Document doc = (Document) objectSocketInput.readObject();
                if (doc==null) return;
                doc.setValid();
                objectSocketOutput.writeObject(doc);
            }


        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
}
