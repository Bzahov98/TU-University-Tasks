package com.tu.bzahov;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;

public class Listener extends Thread {

    private Socket socket;
    static int count = 0;

    public Listener(Socket socket/*, DataInputStream dis, DataOutputStream dos*/){
        this.socket = socket;
        /*this.dis = dis;
        this.dos = dos;*/
    }

    @Override
    public void run(){

        try(PrintStream printout = new PrintStream(socket.getOutputStream())){
            //printout.write();
            printout.print(incrCount() + "---");
            printout.flush();
            System.out.println(this.getId() + " "+ getCount());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int incrCount() {
        return ++count;
    }

    public static int getCount() {
        return count;
    }
}
