import java.io.IOException;
import java.io.PrintWriter;
import java.io.*;
import javax.swing.JOptionPane; 
import chapman.graphics.JPlot2D;
public class Project_2 {
	static double params[] = new double[4];
	public static void main (String[] args) throws IOException {
		double params[] = new double[4];
		FunctionGenerator();
	}
		public static void FunctionGenerator() throws IOException{
			String function = "";
			try{
			int choice = 0;
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
			}catch(NumberFormatException ex){
				JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose a value between 1 and 4");
				FunctionGenerator();
			}
		}
		public static void GenerateSignal() throws IOException{
			String signal = "";
			try{
				int choice;
			signal = JOptionPane.showInputDialog
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
				JOptionPane.showMessageDialog(null, signal + " is not a valid choice. Please choose as value between 1 and 4");
				GenerateSignal();
			}
		}
		public static void Signal(int plot, double params[]) throws IOException{
			double n[] = new double[4]; 
			n = params;
			int graph = 0;
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
			n[0] = Double.parseDouble(choice);
			n[0] = Math.toRadians(n[0]) / 2.77;
			choice = JOptionPane.showInputDialog(null, "Enter amplitude (v): ");
			n[1] = Double.parseDouble(choice) / 2;
			choice = JOptionPane.showInputDialog(null, "Enter phase shift (ms): ");
			n[2] = Double.parseDouble(choice);
			n[2] = Math.toRadians(n[2]);
			choice = JOptionPane.showInputDialog(null, "Enter vertical shift (v): ");
			n[3] = Double.parseDouble(choice);
			GenerateNewSignal(n, graph);	
		}
			catch(NumberFormatException ex){
				JOptionPane.showMessageDialog(null, choice + " is not a valid number. Please try again.");
				Signal(graph, n);
			}
			catch(NullPointerException ex){
				GenerateSignal();
			}
			
		}
		
		public static void GenerateNewSignal(double params[], int graph) throws IOException{
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
				Plot(params, graph);
			} else if (choice == 3){
				Export(params, graph);
			} else if(choice == 4){
				JOptionPane.showMessageDialog(null, "Goodbye");
				System.exit(0);
			} else {
				JOptionPane.showMessageDialog(null, function + " is not a valid choice. Please choose a value between 1 and 4");
				GenerateNewSignal(params, graph);
			}
			}catch(NumberFormatException ex){
				JOptionPane.showMessageDialog(null, function + " is not a valid number. Please try again.");
				GenerateNewSignal(params, graph);
			}
		}
		public static void Export(double params[], int plot) throws IOException{
			boolean graph = false;
			PrintWriter writer = new PrintWriter( new BufferedWriter( new FileWriter("waveform.csv")));
			if(plot == 1){
				SineSignal ss = new SineSignal(params);
				ss.plot(graph);
				for(int i = 0; i < ss.x.length; i++){
				writer.println(ss.x[i] + "," + ss.y[i]);
				}
		} else if(plot == 2){
			SquareSignal ss = new SquareSignal(params);
			ss.plot(graph);
			for(int i = 0; i < ss.x.length; i++){
				writer.println(ss.x[i] + "," + ss.y[i]);
				}
		}else if(plot == 3) {
			SawtoothSignal ss = new SawtoothSignal(params);
			ss.plot(graph);
			for(int i = 0; i < ss.x.length; i++){
				writer.println(ss.x[i] + "," + ss.y[i]);
				}
		}	
			//FunctionGenerator();
			writer.close();
		}
		public static void Plot(double params[], int plot) throws IOException{
			boolean graph = true;
			if(plot == 1){
				SineSignal ss = new SineSignal(params);
				ss.plot(graph);
			} else if(plot == 2){
				SquareSignal ss = new SquareSignal(params);
				ss.plot(graph);
			}else if(plot == 3) {
				SawtoothSignal ss = new SawtoothSignal(params);
				ss.plot(graph);
					}
			FunctionGenerator();
				}
			
		}


