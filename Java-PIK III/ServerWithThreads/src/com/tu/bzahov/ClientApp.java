package com.tu.bzahov;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class ClientApp {
    public static void main(String[] args) {

        try(Socket s = new Socket("localhost", 7777);
            Scanner scan = new Scanner(s.getInputStream());){

            //PrintStream printout = new PrintStream(s.getOutputStream());
            while (true){
                if (scan.hasNextLine()) {
                    String input = scan.nextLine();
                    System.out.println(">> " + input);
                }
            }
            //String output = printout.;
            } catch (IOException e) {
            System.out.println(e.getMessage());
        }catch (NoSuchElementException a){
            System.out.println(a.getMessage());
        }
    }
}
