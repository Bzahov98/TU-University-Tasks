package com.tu.bzahov;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerApp {
    public static final int PORT = 12121;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(PORT);

            while (true){
                Socket socket = null;
                try {
                    socket = serverSocket.accept();
                    System.out.println("A new client is connected : " + socket);
                    Thread thread = new Thread(new ServerAccepterRunnable(socket));
                    thread.start();

                }catch (Exception e){
                    if (socket!= null) socket.close();
                }
            }


        }catch (IOException ignored){}
        finally {
            try {
                if (serverSocket != null) {
                    serverSocket.close();
                }
            }catch (IOException ignored) {}
        }
    }
}

