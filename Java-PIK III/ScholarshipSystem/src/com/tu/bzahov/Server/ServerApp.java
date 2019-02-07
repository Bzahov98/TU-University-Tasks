package com.tu.bzahov.Server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerApp {
    /**
     * Server app
     **/
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
                    /*DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                    DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

                    System.out.println("new tread");
                    */
                    //Thread thread = new Thread(new ServerAccepterRunnable(socket,inputStream,outputStream));
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
