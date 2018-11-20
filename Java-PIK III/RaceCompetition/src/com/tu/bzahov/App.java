package com.tu.bzahov;

import com.tu.bzahov.interfaces.ICompetition;

public class App {

    private static final double MINIMUM_CHANCE_FOR_WIN = 1.1d;

    public static void main(String[] args) {
        // TODO: Add main function
    }

    public static void bets(ICompetition competition, int id, double bet) throws NullPointerException{
        if (competition == null) throw new NullPointerException();
        Participant[] schedule = competition.getSchedule();
        Participant currentParticipant = schedule[id];

        double curBetForWin = currentParticipant.getBetForWin();
        double curChanceForWin = currentParticipant.getChanceForWin();

        double newBetForWin = calculateNewBetForWin(curBetForWin,bet);
        currentParticipant.setBetForWin(newBetForWin);

        double newChanceForWin = calculateNewChanceForWin(curBetForWin,newBetForWin, MINIMUM_CHANCE_FOR_WIN);
        currentParticipant.setChanceForWin(newChanceForWin);
    }

    private static double calculateNewBetForWin(double curBetForWin, double bet) {
        double newBetForWin = 0.0;
        // TODO: 20.11.18 Complete calculation
        return newBetForWin;
    }

    private static double calculateNewChanceForWin(double curBetForWin, double newBetForWin, double minimumChanceForWin) {
        double newChanceForWin = 0.0;
        //value less than 0 if d1 is numerically less than d2

        // TODO: 20.11.18 Complete calculation
        if (Double.compare(newBetForWin,minimumChanceForWin)<0){
            newChanceForWin = 1.1;
        }
        return newChanceForWin;
    }

}
