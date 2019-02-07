package com.tu.bzahov.RolesRunnables;

import com.tu.bzahov.Model.Document;
import com.tu.bzahov.Model.Message;
import com.tu.bzahov.Server.ServerAccepterRunnable;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class StudentRunnable  implements Runnable{

    private int id;
    private Socket socket;
    private ObjectInputStream objectSocketInput;
    private ObjectOutputStream objectSocketOutput;


    public StudentRunnable(Socket socket) {
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
            objectSocketOutput.writeObject(new Message(ServerAccepterRunnable.STUDENT_TYPE));
            objectSocketOutput.writeObject(createDoc());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static Document createDoc() {
        int type = (int) Math.round(Math.random());

        return new Document("Ivan", 4.5, 364, "FKST", false, type);
    }
}
