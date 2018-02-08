/*Name: Ako-Akeem Boyd
 *Professor: Dr. Kofi Nyarko
 *Date: 03/08/2017
 *EEGR 415
*/
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import java.io.*;

import chapman.graphics.JPlot2D;
public class Project1_Ako {
	public static void main (String[] args) throws IOException {
		int option1;
		int option2;
		FunctionGenerator();
	}
		public static void FunctionGenerator() throws IOException{
			String function = "";
			int choice;
			function = JOptionPane.showInputDialog
					(null, " \t \t FUNCTION GENERATOR \n"
					+ "_____________________________ \n" 
					+ "1. Generate Signal \n"
					+ "2. Plot Signal \n"
					+ "3. Export Signal \n"
					+ "4. Exit"
					);
			if(function == null){
				System.exit(0);
			}
			choice = Integer.parseInt(function);
				if(choice == 1){
					GenerateSignal();
				} else if(choice == 2 || choice == 3){
					JOptionPane.showMessageDialog(null, "No signal to plot. Geneate a signal first");
					FunctionGenerator();
				} else if(choice == 4){
					JOptionPane.showMessageDialog(null, "Goodbye");
					System.exit(0);
				} else {
					JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose a value between 1 and 4");
					FunctionGenerator();
				}
			
				
			}
		public static void FunctionGenerator(double a, double b, double c, double d, int graph) throws IOException{
			String function = "";
			int choice;
			function = JOptionPane.showInputDialog
					(null, " \t \t FUNCTION GENERATOR \n"
					+ "_____________________________ \n" 
					+ "1. Generate Signal \n"
					+ "2. Plot Signal \n"
					+ "3. Export Signal \n"
					+ "4. Exit"
					);
			if(function == null){
				System.exit(0);
			}
			choice = Integer.parseInt(function);
				if(choice == 1){
					GenerateSignal();
				} else if(choice == 2){
					Plot(a,b,c,d,graph);
				} else if(choice == 3){
					Export(a,b,c,d,graph);
				} else if(choice == 4){
					JOptionPane.showMessageDialog(null, "Goodbye");
					System.exit(0);
				} else {
					JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose a value between 1 and 4");
					FunctionGenerator(a,b,c,d,graph);
				}
			
				
			}
		
		public static void GenerateSignal() throws IOException{
			int choice;
			String signal = JOptionPane.showInputDialog
					(null, " \t \t GENERATE SIGNAL \n"
					+ "_____________________________ \n" 
					+ "1. Generate Sinusoid Signal \n"
					+ "2. Generate a Square Signal \n"
					+ "3. Generate a Sawtooth Signal \n"
					+ "4. Return");
			if(signal == null){
				System.exit(0);
			}
			choice = Integer.parseInt(signal);
			if(choice == 1 || choice == 2 || choice == 3){
				Signal(choice);
			}else if(choice == 4){
				FunctionGenerator();
			}else if(signal == null){
				System.exit(0);
			}else {
				JOptionPane.showMessageDialog(null, choice + " is not a valid choice. Please choose a value between 1 and 4");
				GenerateSignal();
			}
		}
		public static void Signal(int plot) throws IOException{
			int graph;
			double freq;
			double amp;
			double ps;
			double vs;
			if(plot == 1){
				graph = 1;
			}else if(plot == 2){
				graph = 2;
			}else{
				graph = 3;
			}
			String choice = JOptionPane.showInputDialog(null, "Enter frequency (hz): ");
			freq = Double.parseDouble(choice);
			freq = Math.toRadians(freq) / 2.77;
			choice = JOptionPane.showInputDialog(null, "Enter amplitude (v): ");
			amp = Double.parseDouble(choice) / 2;
			choice = JOptionPane.showInputDialog(null, "Enter phase shift (ms): ");
			ps = Double.parseDouble(choice);
			ps = Math.toRadians(ps);
			choice = JOptionPane.showInputDialog(null, "Enter vertical shift (v): ");
			vs = Double.parseDouble(choice);
			GenerateSignal(freq, amp, ps, vs, graph);	
		}
		
		public static void GenerateSignal(double a, double b, double c, double d, int graph) throws IOException{
			int choice;
			String signal = JOptionPane.showInputDialog
					(null, " \t \t GENERATE SIGNAL \n"
					+ "_____________________________ \n" 
					+ "1. Generate Sinusoid Signal \n"
					+ "2. Generate a Square Signal \n"
					+ "3. Generate a Sawtooth Signal \n"
					+ "4. Return");
			 if(signal == null){
					FunctionGenerator();
			}
			choice = Integer.parseInt(signal);
			if(choice == 1 || choice == 2 || choice == 3){
				Signal(choice);
			} else if(choice == 4){
				FunctionGenerator(a,b,c,d,graph);
			}
			 else {
				JOptionPane.showMessageDialog(null, signal + " is not a valid choice. Please choose a value between 1 and 4");
				GenerateSignal(a,b,c,d,graph);
			}
		}
		public static void Export(double freq, double amp, double phase, double vert, int plot) throws IOException {
			double[] x = new double[2000];
			double[] y = new double[x.length];
			PrintWriter writer = new PrintWriter( new BufferedWriter( new FileWriter("waveform.csv")));
			
			if(plot == 1){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (amp * (Math.sin(freq * x[i] + phase)) + vert);
					writer.println(x[i] + "," + y[i]);
				}
			} else if(plot == 2){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = ((amp * Math.signum(Math.sin(freq * x[i] + phase))) + vert);
					writer.println(x[i] + "," + y[i]);
				}
				
			}else if(plot == 3) {
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (amp * (Math.sin(freq * x[i] + phase)) + vert);
					if(y[i] >= amp){
						y[i] = 0;
					}
					writer.println(x[i] + "," + y[i]);
				}	
			}
			writer.close();
		}
		
		public static void Plot(double freq, double amp, double phase, double vert, int plot){
			double[] x = new double[2000];
			double[] y = new double[x.length];
			if(plot == 1){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (amp * (Math.sin(freq * x[i] + phase)) + vert);
				}
			} else if(plot == 2){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = ((amp * Math.signum(Math.sin(freq * x[i] + phase))) + vert);
				}
				
			}else if(plot == 3) {
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (amp * (Math.sin(freq * x[i] + phase)) + vert);
					if(y[i] >= amp){
						y[i] = 0;
					}
				}
			}
			
			JPlot2D pl = new JPlot2D(x,y);
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
			JFrame fr = new JFrame("EEGR 409: Project 1");
			WindowHandler I = new WindowHandler();
			fr.addWindowListener(I);
			
			fr.getContentPane().add(pl, BorderLayout.CENTER);
			fr.setSize(500, 500);
			fr.setVisible(true);
			class WindowHandler extends WindowAdapter{
				public void windowClosing(WindowEvent e){
					System.exit(0);
		}
		
			}
		}
		
}