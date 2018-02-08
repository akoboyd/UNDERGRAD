/*Name: Ako-Akeem Boyd
 *Professor: Dr. Kofi Nyarko
 *Date: 04/26/2017
 *EEGR 415
*/
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import javax.swing.*;

import chapman.graphics.JPlot2D;

public class Project2_2_Ako extends JPanel{
	private JButton genSignal, exSignal;
	private JComboBox graphs;
	private JLabel Freq, Amp, Phase, Vert;
	private JTextField box1, box2, box3, box4;
	private static double params[] = new double[4];
	static double[] x;
	static double[] y;
	private static int plot;
	private JPlot2D pl;
	boolean export = false;
	private static JFrame fr;
	
	public void init() {
		setLayout(null);
		pl = new JPlot2D(x,y);
		pl.setBounds(0, 0, 590, 300);;
		pl.setPlotType(JPlot2D.LINEAR);
		pl.setLineColor(Color.blue);
		pl.setLineWidth(1.0f);
		pl.setLineStyle(JPlot2D.LINESTYLE_SOLID);
		//pl.setMarkerState(JPlot2D.MARKER_ON);
		pl.setMarkerColor(Color.red);
		pl.setMarkerStyle(JPlot2D.MARKER_DIAMOND);
		pl.setTitle("Waveform Plot");
		pl.setXLabel("time (ms)");
		pl.setYLabel("amplitude (v)");
		pl.setGridState(JPlot2D.GRID_ON);
		add(pl);
		pl.setVisible(true);
		
		genSignal = new JButton("Generate Signal");
		genSignal.addActionListener(new GenerateSignal(this));
		genSignal.setBounds(10, 425, 125, 23);
		
		exSignal = new JButton("Export Signal");
		exSignal.addActionListener(new ExportSignal(this, params));
		exSignal.setBounds(145, 425, 125, 23);
		exSignal.setEnabled(false);
		
		String [] plots = {"Sine Wave", "Square Wave", "Sawtooth Wave"};
		graphs = new JComboBox(plots);
		graphs.addActionListener(new Plot(this));
		graphs.setBounds(10, 375, 125, 23);
		
		Freq = new JLabel("Frequency (Hz):");
		Freq.setBounds(10, 325, 87, 23);
		box1 = new JTextField();
		box1.addActionListener(new Frequency(this));
		box1.setBounds(100, 325, 40, 23);
			
		Amp = new JLabel("Amplitude (v):");
		Amp.setBounds(145, 325, 87, 23);
		box2 = new JTextField();
		box2.addActionListener(new Amplitude(this));
		box2.setBounds(225, 325, 40, 23);
		
		Phase = new JLabel("Phase (deg):");
		Phase.setBounds(275, 325, 87, 23);
		box3 = new JTextField();
		box3.addActionListener(new Phase(this));
		box3.setBounds(350, 325, 40, 23);
		
		Vert = new JLabel("Vertical Shift (v):");
		Vert.setBounds(400, 325, 100, 23);
		box4 = new JTextField();
		box4.addActionListener(new Vertical(this));
		box4.setBounds(495, 325, 40, 23);
		
		add(genSignal);
		add(exSignal);
		add(graphs);
		add(Freq);
		add(box1);
		add(Amp);
		add(box2);
		add(Phase);
		add(box3);
		add(Vert);
		add(box4);
	}
	
	public static void main (String s[]){
		x = new double[2000]; 
		y = new double[x.length];
		plot = 1;
		for(int i = 0; i < x.length; i++){
			x[i] = i;
			y[i] = 0;
		}
		fr = new JFrame("EEGR Project 2");

		fr.setSize(600, 500);
		Project2_2_Ako fg = new Project2_2_Ako();
		fg.init();
		
		
		WindowHandler l = new WindowHandler();
		fr.addWindowListener(l);
		
		fr.getContentPane().add(fg);
		fr.setVisible(true);
	}
		public void UpdateFreq(double f){
			params[0] = f;
			params[0] = Math.toRadians(params[0]) / 2.77;
			System.out.println(params[0]);
		}
		public void UpdateAmp(double a){
			params[1] = a;
			params[1] /= 2;	
			System.out.println(params[1]);
		}
		public void UpdatePhase(double p){
			params[2] = p;
			Math.toRadians(params[2]);
			System.out.println(params[2]);
			
		}
		public void UpdateVert(double v){
			params[3] = v;
			System.out.println(params[3]);
		}
		public void GenSig(){
			if(plot == 1){
				SineSignal ss = new SineSignal(params);
				ss.plot();
				x = ss.getXvalues();
				y = ss.getYvalues();
				UpdateGraph();
				
			} else if(plot == 2){
				SquareSignal ss = new SquareSignal(params);
				ss.plot();
				x = ss.getXvalues();
				y = ss.getYvalues();
				UpdateGraph();
				 
			}else if(plot == 3) {
				SawtoothSignal ss = new SawtoothSignal(params);
				ss.plot();
				x = ss.getXvalues();
				y = ss.getYvalues();
				UpdateGraph();
			}
		}
		public void UpdatePlot(String p){
			if(p == "Sine Wave"){
				plot = 1;
				
				
			}else if(p == "Square Wave"){
				plot = 2;
				
				
			}else if(p == "Sawtooth Wave"){
				plot = 3;
				
			}
		}
		
		public int getPlot(){
			return plot;
		}
		
		public void UpdateGraph(){
			pl.removeAll();
			fr.setVisible(false);
			pl.addCurve(x, y);
			fr.setVisible(true);
			
			exSignal.setEnabled(true);
		}
		public JTextField getText1(){
			return box1;
		}
		public JTextField getText2(){
			return box2;
		}
		public JTextField getText3(){
			return box3;
		}
		public JTextField getText4(){
			return box4;
		}
	}

abstract class Signal{
	double[] params = new double[4];
	double[] x = new double[2000];
	double[] y = new double[x.length];
	
	public Signal(double[] p){
		params = p;
	}
	abstract public void plot();
	
	public double[] getXvalues(){
		return x;
	}
	public double[] getYvalues(){
		return y;
	}
}

class SquareSignal extends Signal{
	public SquareSignal(double[] p){
		super(p);
	}
	public void plot(){
		for (int i = 0; i < x.length; i++){
			x[i] = i;
			y[i] = (params[1] * (Math.signum(Math.sin((params[0] * x[i] + params[2])) + params[3])));
		}
	}
}
class SineSignal extends Signal{
	public SineSignal(double[] p){
		super(p);
	}
	public void plot(){
		for (int i = 0; i < x.length; i++){
			x[i] = i;
			y[i] = (params[1] * (Math.sin(params[0] * x[i] + params[2])) + params[3]);
			System.out.println(y[i]);
		}
	}
}

class SawtoothSignal extends Signal{
	public SawtoothSignal(double[] p){
		super(p);
	}
	public void plot(){
		for (int i = 0; i < x.length; i++){
			x[i] = i;
			y[i] = (params[1] * (Math.sin(params[0] * x[i] + params[2])) + params[3]);
			if(y[i] >= params[1]){
				y[i] = 0;
				}
			}
		}
	}

class WindowHandler extends WindowAdapter{
	public void windowClosing(WindowEvent e){
		System.exit(0);
	}

}

class Frequency implements ActionListener{
	
	private Project2_2_Ako fg;
	private JTextField b;
	public Frequency(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
		try{
			int number = 0;
			String input = "";
			input = e.getActionCommand();
			number = Integer.parseInt(input);
			fg.UpdateFreq(number);
}
		catch(NumberFormatException ex){
			JOptionPane.showMessageDialog(null, "Frequency specified is invalid");
			b = fg.getText1();
			b.setText("");
		}
	}
}

class Amplitude implements ActionListener{
	
	private Project2_2_Ako fg;
	private JTextField b;
	public Amplitude(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
		try{
			int number = 0;
			String input = "";
			input = e.getActionCommand();
			number = Integer.parseInt(input);
			fg.UpdateAmp(number);
}
		catch(NumberFormatException ex){
			JOptionPane.showMessageDialog(null, "Amplitude specified is invalid");
			b = fg.getText2();
			b.setText("");
		}
	}
}

class Phase implements ActionListener{
	
	private Project2_2_Ako fg;
	private JTextField b;
	public Phase(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
		try{
			int number = 0;
			String input = "";
			input = e.getActionCommand();
			number = Integer.parseInt(input);
			fg.UpdatePhase(number);
}
		catch(NumberFormatException ex){
			JOptionPane.showMessageDialog(null, "Phase Shift specified is invalid");
			b = fg.getText3();
			b.setText("");
		}
	}
}

class Vertical implements ActionListener{
	
	private Project2_2_Ako fg;
	private JTextField b;
	public Vertical(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
		try{
			int number = 0;
			String input = "";
			input = e.getActionCommand();
			number = Integer.parseInt(input);
			fg.UpdateVert(number);
}
		catch(NumberFormatException ex){
			JOptionPane.showMessageDialog(null, "Vertical Shift specified is invalid");
			b = fg.getText4();
			b.setText("");
		}
	}
}

class GenerateSignal implements ActionListener{
	
	private Project2_2_Ako fg;
	public GenerateSignal(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
			fg.GenSig();
	}
}


class Plot implements ActionListener{
	
	private Project2_2_Ako fg;
	public Plot(Project2_2_Ako fg1){
		fg = fg1;
	}
	public void actionPerformed(ActionEvent e){
	
			JComboBox p = (JComboBox)e.getSource();
			String input = (String)p.getSelectedItem();
			fg.UpdatePlot(input);
	}
}

class ExportSignal implements ActionListener{
	
	private Project2_2_Ako fg;
	private int p;
	private double[] params;
	double[] x = new double[2000];
	double[] y = new double[x.length];
	public ExportSignal(Project2_2_Ako fg1, double[] param){
		fg = fg1;
		params = param;
	}
	public void actionPerformed(ActionEvent e){
			p = fg.getPlot();
			System.out.println(p);
			Project2_2_Ako ss = new Project2_2_Ako();
			try {
				PrintWriter writer = new PrintWriter( new BufferedWriter( new FileWriter("waveform.csv")));
				
				if(p == 1){
					for (int i = 0; i < x.length; i++){
						x[i] = i;
						y[i] = (params[1] * (Math.sin(params[0] * x[i] + params[2])) + params[3]);
						writer.println(x[i] + "," + y[i]);
					}
				} else if(p == 2){
					for (int i = 0; i < x.length; i++){
						x[i] = i;
						y[i] = (params[1] * (Math.signum(params[0] * x[i] + params[2])) + params[3]);
						writer.println(x[i] + "," + y[i]);
					}
					
				}else if(p == 3) {
						for (int i = 0; i < x.length; i++){
							x[i] = i;
							y[i] = (params[1] * (Math.sin(params[0] * x[i] + params[2])) + params[3]);
							if(y[i] >= params[1]){
								y[i] = 0;
						}
						writer.println(x[i] + "," + y[i]);
					}	
				}
				writer.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
	}
