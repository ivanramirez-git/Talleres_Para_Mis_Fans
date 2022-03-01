/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.example.Ventana;

import com.example.Controlador.ControladorVentanaVehiculos;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.LineBorder;

/**
 *
 * @author dell
 */
public class VentanaVehiculos extends JFrame{
    
   public JLabel lbltipoauto, lblañoauto, lbltipocambio, lbladiciones;
    public JComboBox cbTipoauto;
    public JTextField txtAñoauto;
    public JRadioButton manual, automatico;
    public JCheckBox p1,p2,p3;
   public JButton btnCalcular, btnCancelar;
    
    public VentanaVehiculos(){
        
        iniciar();
    }

    private void iniciar() {

        this.setTitle("Cotizador de Vehiculo");
        this.setSize(750, 600);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        FlowLayout flow = new FlowLayout(FlowLayout.CENTER, 30, 60);
        this.setLayout(flow);

        GridLayout grid = new GridLayout(6, 3, 25,25);
        this.setLayout(grid);

        lbltipoauto = new JLabel("Tipo de Vehiculo:");
        lbltipoauto.setFont(new Font("Cambria",Font.BOLD,14));
        this.add(lbltipoauto);

        String[] hd = {"SUV", "Furgoneta", "Sedan"};
        cbTipoauto = new JComboBox(hd);
        cbTipoauto.setName("SUV");
        cbTipoauto.setName("Furgoneta");
        cbTipoauto.setName("Sedan");
        this.add(cbTipoauto);

        lblañoauto = new JLabel("Año:");
         lblañoauto.setFont(new Font("Cambria",Font.BOLD,14));
        this.add(lblañoauto);
        txtAñoauto = new JTextField();
        txtAñoauto.setName("2022");
        txtAñoauto.setText("0");
        this.add(txtAñoauto);

        lbltipocambio = new JLabel("Tipo de Cambio:");
         lbltipocambio.setFont(new Font("Cambria",Font.BOLD,14));
        this.add(lbltipocambio);
        manual = new JRadioButton("Manual");
        manual.setFont(new Font("Cambria",Font.BOLD,13));
        manual.setName("Manual");
        automatico = new JRadioButton ("Automatico");
        automatico.setName("Automatico");
        automatico.setFont(new Font("Cambria",Font.BOLD,13));

        ButtonGroup tipcambio = new ButtonGroup();
        tipcambio.add(manual);
        tipcambio.add(automatico);

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.setBorder(new LineBorder(Color.BLUE));

        panel.add(manual);
        panel.add(automatico);
        this.add(panel);

        lbladiciones = new JLabel("Adicionales:");
         lbladiciones.setFont(new Font("Cambria",Font.BOLD,14));
        this.add(lbladiciones);

        p1 = new JCheckBox("Aire Acondicionado");
        p1.setName("Aire Acondicionado");
        p2 = new JCheckBox("Sistema integrado de navegacion");
        p2.setName("Sistema integrado de navegacion");
        p3= new JCheckBox("Asientos de piel");
        p3.setName("Asientos de piel");

        panel = new JPanel();
            panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
            panel.add(p1);
            panel.add(p2);
            panel.add(p3);
            this.add(panel);
            JScrollPane sp=new JScrollPane(panel);
            this.add(sp);

        btnCalcular = new JButton("Calcular");
        btnCalcular.setName("btnCalcular");
        this.add(btnCalcular);

        btnCancelar = new JButton("Cancelar");
        btnCancelar.setName("btnCancelar");
        this.add(btnCancelar);
        
//        JLabel lblImagen2 = new JLabel();
//        ImageIcon imagen = new ImageIcon("src/imagen/Furgoneta.jpg");
//        lblImagen2.setIcon(imagen);
//        this.add(lblImagen2);
            
//
    }
    
    public static void main(String[] args) {
        VentanaVehiculos v2 = new VentanaVehiculos(); 
             
             v2.setVisible(true);
             ControladorVentanaVehiculos controlador2 = new ControladorVentanaVehiculos(v2);
    }
}


