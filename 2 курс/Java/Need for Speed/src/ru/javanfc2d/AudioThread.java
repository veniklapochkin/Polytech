package ru.javanfc2d;


import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;
public class AudioThread implements Runnable {


	public void run() {
		try {
			Player	player = new Player(getClass().getClassLoader().getResourceAsStream("Music/�.�. �������� - �������� 9 (����� �.�������) - Ode an die Freude (��� � �������)1.mp3"));
			player.play();
		} catch (JavaLayerException e) {
			e.printStackTrace();
		}
	}

}
