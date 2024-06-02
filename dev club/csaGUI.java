import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;

public class csaGUI extends JFrame {

    public csaGUI() {
        // Set the frame title
        setTitle("CSA GUI");

        // Set the program to exit when the x is clicked
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Add a sample label
        JLabel label = new JLabel("Hello, CSA!");
        add(label);

        // Automatically set the size of the window to fit the preferred size and layouts of the subcomponents
        pack();

        // Make the GUI visible
        setVisible(true);
    }

    public static void main(String[] args) {
        // Schedule a job for the event dispatching thread: creating and showing this application's GUI
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new csaGUI();
            }
        });
    }
}