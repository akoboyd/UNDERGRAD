/*Name: Ako-Akeem Boyd
 *Professor: Dr. Kofi Nyarko
 *Date: 03/14/2017
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

public class Project2_1_Ako {
	public static void main (String[] args) throws IOException {
		int option1;
		int option2;
		FunctionGenerator();
	}
		public static void FunctionGenerator() throws IOException{
			String function = "";
			try{
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
				catch(NumberFormatException ex){
					JOptionPane.showMessageDialog(null, function + " is not a valid number. Please try again.");
					FunctionGenerator();
				}
				
		}
		public static void FunctionGenerator(double params[], int graph) throws IOException{
			String function = "";
			try{
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
					if(graph == 1){
						SineSignal ss = new SineSignal(params);
						ss.plot();
					}else if(graph == 2){
						SquareSignal ss = new SquareSignal(params);
						ss.plot();
					}else if(graph == 3){
						SawtoothSignal ss = new SawtoothSignal(params);
					};
				} else if(choice == 3){
					Export(params, graph);
				} else if(choice == 4){
					JOptionPane.showMessageDialog(null, "Goodbye");
					System.exit(0);
				} else {
					JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose a value between 1 and 4");
					FunctionGenerator(params,graph);
				}
			}catch(NumberFormatException ex){
				JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose as value between 1 and 4");
				FunctionGenerator(params, graph);
		}
			
				
			}
		
		public static void GenerateSignal() throws IOException{
			int choice = 0;
			try{
			double params[] = new double[4];
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
				Signal(choice, params);
			}else if(choice == 4){
				FunctionGenerator();
			}else if(signal == null){
				System.exit(0);
			}else {
				JOptionPane.showMessageDialog(null, choice + " is not a valid choice. Please choose a value between 1 and 4");
				GenerateSignal();
				}
			}catch(NumberFormatException ex){
				JOptionPane.showMessageDialog(null, choice + " is not a valid choice. Please choose as value between 1 and 4");
				GenerateSignal();
			}
		}
		public static void Signal(int plot, double params[]) throws IOException{
			double p[] = new double[4];
			p = params;
			int graph = 0;
			double freq;
			double amp;
			double ps;
			double vs;
			String choice = " ";
			try{
			if(plot == 1){
				graph = 1;
			}else if(plot == 2){
				graph = 2;
			}else{
				graph = 3;
			}
			choice = JOptionPane.showInputDialog(null, "Enter frequency (hz): ");
			freq = Double.parseDouble(choice);
			freq = Math.toRadians(freq) / 2.77;
			p[0] = freq;
			choice = JOptionPane.showInputDialog(null, "Enter amplitude (v): ");
			amp = Double.parseDouble(choice) / 2;
			p[1] = amp;
			choice = JOptionPane.showInputDialog(null, "Enter phase shift (ms): ");
			ps = Double.parseDouble(choice);
			ps = Math.toRadians(ps);
			p[2] = ps;
			choice = JOptionPane.showInputDialog(null, "Enter vertical shift (v): ");
			vs = Double.parseDouble(choice);
			p[3] = vs;
			GenerateSignal(p, graph);	
		}
		catch(NumberFormatException ex){
			JOptionPane.showMessageDialog(null, choice + " is not a valid number. Please try again.");
			Signal(graph, p);
		}
		catch(NullPointerException ex){
			GenerateSignal();
		}
	}
		
		public static void GenerateSignal(double params[], int graph) throws IOException{
			int choice;
			String signal = " ";
			try{
				signal = JOptionPane.showInputDialog
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
				Signal(choice, params);
			} else if(choice == 4){
				FunctionGenerator(params, graph);
			}
			 else {
				JOptionPane.showMessageDialog(null, signal + " is not a valid choice. Please choose a value between 1 and 4");
				GenerateSignal(params, graph);
			 	}
			}
			catch(NumberFormatException ex){
					JOptionPane.showMessageDialog(null, signal + " is not a valid number. Please try again.");
					GenerateSignal(params, graph);
				}
			
		}
		
		public static void Export(double p[], int plot) throws IOException {
			double[] x = new double[2000];
			double[] y = new double[x.length];
			double params[] = p;
			PrintWriter writer = new PrintWriter( new BufferedWriter( new FileWriter("waveform.csv")));
			
			if(plot == 1){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (params[1] * (Math.sin(params[0] * x[i] + params[2])) + params[3]);
					writer.println(x[i] + "," + y[i]);
				}
			} else if(plot == 2){
				for (int i = 0; i < x.length; i++){
					x[i] = i;
					y[i] = (params[1] * (Math.signum(params[0] * x[i] + params[2])) + params[3]);
					writer.println(x[i] + "," + y[i]);
				}
				
			}else if(plot == 3) {
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
		}
}
	
		
abstract class Signal{
	double[] params = new double[4];
	double[] x = new double[2000];
	double[] y = new double[x.length];
	
	public Signal(double[] p){
		params = p;
	}
	public void display(double[] x1, double y1[]){
		JPlot2D pl = new JPlot2D(x1,y1);
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
	}
		
abstract public void plot();
}

class WindowHandler extends WindowAdapter{
	public void windowClosing(WindowEvent e){
		System.exit(0);
	}

}

class SquareSignal extends Signal{
	public SquareSignal(double[] p){
		super(p);
	}
	public void plot(){
		for (int i = 0; i < x.length; i++){
			x[i] = i;
			y[i] = (params[1] * (Math.signum(params[0] * x[i] + params[2])) + params[3]);
			}
		super.display(x, y);
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
			}
		super.display(x, y);
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
		super.display(x, y);
		}
	}


