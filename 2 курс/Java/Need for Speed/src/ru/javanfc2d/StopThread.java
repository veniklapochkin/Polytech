package ru.javanfc2d;

public class StopThread implements Runnable {
	public void run() {
		{
			int seconds = 0, minutes = 0;
			while (true) {
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO ������������� ��������� ���� catch
					e.printStackTrace();
				}
				seconds++;
				if (minutes != 0)
					System.out.print(minutes + ":");
				System.out.println(seconds);
				if (seconds == 59) {
					seconds = -1;
					minutes++;
				}
			}
		}
	}

}
