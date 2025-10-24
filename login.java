import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class login {
    private static final String USERNAME = "admin";
    private static final String PASSWORD = "password123";

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Simple Login");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setResizable(false);

            JPanel panel = new JPanel(new GridBagLayout());
            GridBagConstraints gbc = new GridBagConstraints();
            gbc.insets = new Insets(6, 6, 6, 6);
            gbc.fill = GridBagConstraints.HORIZONTAL;

            JLabel userLabel = new JLabel("Username:");
            gbc.gridx = 0;
            gbc.gridy = 0;
            panel.add(userLabel, gbc);

            JTextField userField = new JTextField(15);
            gbc.gridx = 1;
            panel.add(userField, gbc);

            JLabel passLabel = new JLabel("Password:");
            gbc.gridx = 0;
            gbc.gridy = 1;
            panel.add(passLabel, gbc);

            JPasswordField passField = new JPasswordField(15);
            gbc.gridx = 1;
            panel.add(passField, gbc);

            JCheckBox showPass = new JCheckBox("Show");
            gbc.gridx = 1;
            gbc.gridy = 2;
            gbc.anchor = GridBagConstraints.WEST;
            panel.add(showPass, gbc);

            JLabel message = new JLabel(" ");
            message.setForeground(Color.RED);
            gbc.gridx = 0;
            gbc.gridy = 3;
            gbc.gridwidth = 2;
            panel.add(message, gbc);

            JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT));
            JButton loginBtn = new JButton("Login");
            JButton resetBtn = new JButton("Reset");
            buttons.add(resetBtn);
            buttons.add(loginBtn);

            gbc.gridx = 0;
            gbc.gridy = 4;
            gbc.gridwidth = 2;
            gbc.anchor = GridBagConstraints.EAST;
            panel.add(buttons, gbc);

            // Actions
            ActionListener attemptLogin = e -> {
                String user = userField.getText().trim();
                String pass = new String(passField.getPassword());
                if (USERNAME.equals(user) && PASSWORD.equals(pass)) {
                    message.setForeground(new Color(0, 128, 0));
                    message.setText("Login successful.");
                    JOptionPane.showMessageDialog(frame, "Welcome, " + USERNAME + "!", "Success", JOptionPane.INFORMATION_MESSAGE);
                    // proceed to next step in a real app
                } else {
                    message.setForeground(Color.RED);
                    message.setText("Invalid username or password.");
                    passField.setText("");
                }
            };

            loginBtn.addActionListener(attemptLogin);
            passField.addActionListener(attemptLogin); // Enter to submit
            resetBtn.addActionListener(e -> {
                userField.setText("");
                passField.setText("");
                message.setText(" ");
            });

            showPass.addActionListener(e -> {
                if (showPass.isSelected()) {
                    passField.setEchoChar((char) 0);
                } else {
                    passField.setEchoChar('\u2022');
                }
            });

            frame.getContentPane().add(panel);
            frame.pack();
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}