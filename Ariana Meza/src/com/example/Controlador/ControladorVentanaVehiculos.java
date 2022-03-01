/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.example.Controlador;

import com.example.Modelos.Vehiculos;
import com.example.Ventana.VentanaVehiculos;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author dell
 */
public class ControladorVentanaVehiculos {
    
    
     private VentanaVehiculos v2;


    public ControladorVentanaVehiculos() {
    }

    public ControladorVentanaVehiculos(VentanaVehiculos ventana) {
        this.v2 = ventana; 
    
     // escucha de eventos para textfield
        MyKeyListener mykey = new MyKeyListener();
        this.v2.txtAñoauto.addKeyListener(mykey);
     
        // escucha de eventos para combobox
         MyItemListener myitem = new MyItemListener();
         this.v2.cbTipoauto.addItemListener(myitem);
         
         
         MyActionListener mal= new MyActionListener();
         this.v2.btnCalcular.addActionListener(mal);
         this.v2.btnCancelar.addActionListener(mal);

}
    public void leerDatos2() {
        Vehiculos veh = new Vehiculos();

        String tipoveh = this.v2.cbTipoauto.getSelectedItem().toString();
        
        int anio = 0;
        try {
            anio = Integer.parseInt(this.v2.txtAñoauto.getText());
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error en el año de fabricacion, no puede estar vacio");
        }
        
        String tipocam = "";
        if (this.v2.p1.isSelected()) {
            tipocam = this.v2.p1.getText();
        } else if (this.v2.p2.isSelected()) {
            tipocam = this.v2.p2.getText();
        } else if (this.v2.p3.isSelected()){
            tipocam = this.v2.p3.getText(); 
         }
          String adic  =this.v2.p1.getText();
          String adic1 = this.v2.p2.getText();
          String adic2 = this.v2.p3.getText();
        

        veh.setTipoVehiculo(tipoveh);
        veh.setAño(adic);
        veh.setTipoCambio(tipocam);
        veh.setAdicionales(adic2);
        veh.calcularPrecio();

        JOptionPane.showMessageDialog(null, veh.toString());
        
    }

    // leerDatos
    public void leerDatos() {
        boolean error = false;
        Vehiculos veh = new Vehiculos();
        veh.setTipoVehiculo(this.v2.cbTipoauto.getSelectedItem().toString());
        // Validar el tipo de vehiculo
        if (veh.getTipoVehiculo().equals("")) {
            JOptionPane.showMessageDialog(null, "Debe seleccionar un tipo de vehiculo");
            error = true;
        } else {
            if (veh.getTipoVehiculo().equals("SUV")) {
                veh.setTipoVehiculo("SUV");
            } else if (veh.getTipoVehiculo().equals("Sedan")) {
                veh.setTipoVehiculo("Sedan");
            } else if (veh.getTipoVehiculo().equals("Furgoneta")) {
                veh.setTipoVehiculo("Furgoneta");
            } else {
                // Error
                JOptionPane.showMessageDialog(null, "Debe seleccionar un tipo de vehiculo");
                error = true;
            }
        }

        veh.setAño(this.v2.txtAñoauto.getText());
        // Validar que sea un año valido
        if (veh.getAño().equals("")) {
            JOptionPane.showMessageDialog(null, "Error en el año de fabricacion, no puede estar vacio");
            error = true;
        }
        int anio = 0;
        try {
            anio = Integer.parseInt(veh.getAño());
            if (anio < 1900 || anio > 2022) {
                JOptionPane.showMessageDialog(null, "Error en el año de fabricacion, no puede ser menor a 1900 ni mayor a 2022");
                error = true;
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error en el año de fabricacion");
            error = true;
        }

        // radio button
        if (this.v2.manual.isSelected()) {
            veh.setTipoCambio("Manual");
        } else if (this.v2.automatico.isSelected()) {
            veh.setTipoCambio("Automatico");
        } else {
            JOptionPane.showMessageDialog(null, "Seleccione una opcion de cambio");
            error = true;
        }

        // Verificar si esta seleccionado p1,p2,p3
        if (this.v2.p1.isSelected()) {
            veh.setAdicionales("P1");
        } else if (this.v2.p2.isSelected()) {
            veh.setAdicionales("P2");
        } else if (this.v2.p3.isSelected()) {
            veh.setAdicionales("P3");
        } else if (this.v2.p1.isSelected() && this.v2.p2.isSelected()) {
            veh.setAdicionales("P1,P2");
        } else if (this.v2.p1.isSelected() && this.v2.p3.isSelected()) {
            veh.setAdicionales("P1,P3");
        } else if (this.v2.p2.isSelected() && this.v2.p3.isSelected()) {
            veh.setAdicionales("P2,P3");
        } else if (this.v2.p1.isSelected() && this.v2.p2.isSelected() && this.v2.p3.isSelected()) {
            veh.setAdicionales("P1,P2,P3");
        }

        if(!error){
            veh.calcularPrecio();
            JOptionPane.showMessageDialog(null, veh.toString());
        }
    }
    
  public void limpiar() {
        this.v2.txtAñoauto.setText("");
        

    }
    class MyActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {
                        
            JButton btn = (JButton) ae.getSource();
            switch (btn.getName()) {
                case "btnCalcular":

                    leerDatos(); 
                    
                    break;
                case "btnCancelar":
                    limpiar();
                    int respuesta =  JOptionPane.showConfirmDialog(null, "¿Está seguro de cancelar el registro de datos?", "Salones VIP", 
                            JOptionPane.YES_NO_OPTION);
                   if(respuesta == JOptionPane.YES_NO_OPTION){
                    System.exit(0);
                    
                }else if (respuesta == JOptionPane.NO_OPTION){

                } 
            }

        }
    }
    
    // CLASE INTERNA PARA MANEJAR EVENTOS DE TECLADO
    class MyKeyListener extends KeyAdapter {
        @Override
        public void keyTyped(KeyEvent ke) {
            JTextField txt = (JTextField) ke.getSource();// caja de texto sobre la
            // que se dio el evento de teclado
            Character c = ke.getKeyChar();// obtener el caracter que se ha tipeado
            // validacion
            boolean valido = true;
            if (txt == v2.txtAñoauto) {
                if (!Character.isDigit(c) && c != KeyEvent.VK_SPACE && c != KeyEvent.VK_BACK_SPACE
                        && c != KeyEvent.VK_DELETE) {
                    valido = false;
                }
                if (txt.getText().length() >= 4) {
                    valido = false;
                }

            
           if(!valido){
                ke.consume();// consume ele evento para eviatr que se de, en otras palabras
                // evita que se dibuje la tecla.
            }                     
         }  
      }   
    
    }
   
    // CLASE INTERNA PARA MANEJAR EVENTOS DE COMBOBOX
    class MyItemListener implements ItemListener{

        @Override
        public void itemStateChanged(ItemEvent ie) {
            JComboBox cmb = (JComboBox)ie.getSource();
            String seleccionado = cmb.getSelectedItem().toString();
            
            if (null != seleccionado)switch (seleccionado) {
                case "Furgoneta":
                    v2.lbltipoauto.setIcon(new ImageIcon("src/imagen/Furgoneta.jpg"));
                    break;
                case "SUV":
                    v2.lbltipoauto.setIcon(new ImageIcon("src/imagen/SUV.jpg"));
                    break;
                case "Sedan":
                    v2.lbltipoauto.setIcon(new ImageIcon("src/imagen/Sedan.jpg"));
                    break;
                default:
                    break;
            }
            
        }  
    }
    

}
