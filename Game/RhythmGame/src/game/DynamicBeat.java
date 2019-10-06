package game;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class DynamicBeat extends JFrame{
	
	private Image screenImage;
	private Graphics screenGraphic;
	
	private Image introBackGround = new ImageIcon(Main.class.getResource("../Images/MainBackground.jpg")).getImage();
	
	private JLabel menuBar = new JLabel(new ImageIcon(Main.class.getResource("../Images/MenuBarImage.png")));
	
	private ImageIcon exitButtonEnteredImage = new ImageIcon(Main.class.getResource("../Images/exitButtonImage2.png"));
	private ImageIcon exitButtonBasicImage =  new ImageIcon(Main.class.getResource("../Images/exitButtonImage1.png"));
	private JButton exitButton = new JButton(exitButtonBasicImage);
	
	private ImageIcon startButtonImage = new ImageIcon(Main.class.getResource("../Images/StartButtonImage.png"));
	private ImageIcon endButtonImage = new ImageIcon(Main.class.getResource("../Images/EndButtonImage.png"));
	
	private int mouseX, mouseY;
	
	
	public DynamicBeat() {
		setUndecorated(true);
		setTitle("DynamicBeat");
		setSize(Main.SCREEN_WIDTH, Main.SCREEN_HEIGHT);
		setResizable(false);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		setBackground(new Color(0,0,0,0));
		setLayout(null);
		
		
		//이미지 수정필요 메뉴 종료버튼
				exitButton.setBounds(1165, 0, 30, 30);
				exitButton.setBorderPainted(false);
				exitButton.setContentAreaFilled(false);
				exitButton.setFocusPainted(false);
				exitButton.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseEntered(MouseEvent e) {
						exitButton.setIcon(exitButtonEnteredImage);
						exitButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
						//버튼누르면 소리나게
						//Music buttonEnteredMusic = new Music("buttonEnteredMusic", false);
						//buttonEnteredMusic.start();
					}
					@Override
					public void mouseExited(MouseEvent e) {
						exitButton.setIcon(exitButtonBasicImage);
						exitButton.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
					}
					@Override
					public void mousePressed(MouseEvent e) {
						//종료시 1초정도 기다렸다가 스레드 종료 
						//Music buttonPressedMusic = new Music("buttonpressedMusic", false);
						//buttonpressedMusic.start();
						//try {
						//	Thread.sleep(1000);
						//}
						//catch(InterruptedException ex) {
						//	ex.printStackTrace();
					//	}
						System.exit(0);
					}
				});
				
		
		add(exitButton);
		
		//메뉴바
		menuBar.setBounds(0,0,1200,30);
		menuBar.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				mouseX = e.getX();
				mouseY = e.getY();
			}
		});
		menuBar.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				int x = e.getXOnScreen();
				int y = e.getYOnScreen();
				setLocation(x - mouseX, y - mouseY);
			}
		});
			
		add(menuBar);
		
		
		
		
		Music introMusic = new Music("introMusic.mp3", true);
		introMusic.start();
	}
	public void paint(Graphics g) {
		screenImage = createImage(Main.SCREEN_WIDTH, Main.SCREEN_HEIGHT);
		screenGraphic = screenImage.getGraphics();
		screenDraw(screenGraphic);
		g.drawImage(screenImage,0,0,null);
	}
	public void screenDraw(Graphics g) {
		g.drawImage(introBackGround, 0,0,null);
		//고정된 이미지는 paintcomponents를 이용
		paintComponents(g);
		this.repaint();
	}
}
