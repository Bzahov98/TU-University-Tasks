package com.tu.bzahov.Factories;

import com.tu.bzahov.Model.Document;
import com.tu.bzahov.Model.Message;
import com.tu.bzahov.Server.ServerAccepterRunnable;
import com.tu.bzahov.Server.ServerApp;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class StudentFactory {
    public static void main(String[] args) throws IOException, InterruptedException {
        for (int i = 0; i < 5; i++) {
            Socket socket = new Socket("localhost", ServerApp.PORT);

//            PrintStream socketOutput = new PrintStream(socket.getOutputStream());
//            Scanner socketInput = new Scanner(socket.getInputStream());
            ObjectOutputStream objectSocketOutput = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream());

            objectSocketOutput.writeObject(new Message(ServerAccepterRunnable.STUDENT_TYPE));
            objectSocketOutput.writeObject(createDoc());
        }
    }

    private static Document createDoc() {
        double grade = Math.random() * 4 + 2;
        double income = Math.random() * 600 + 150;
        int type = (int) Math.round(Math.random());

        return new Document("Kiro", grade, income, "FKST", false, type);
    }
}
