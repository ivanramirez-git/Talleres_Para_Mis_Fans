/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ejercicio7.Controlador;

import ejercicio7.Modelo.ConectarBD;
import ejercicio7.Vista.VentanaInsertarConsultar;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author User
 */
public class ControladorInsertarConsultar implements ActionListener {

    VentanaInsertarConsultar objetoVista;
    ConectarBD objetoModelo;
    ArrayList<ActionListener> objetoControlador;

    public ControladorInsertarConsultar() {
        this.objetoVista = new VentanaInsertarConsultar();
        this.objetoModelo = new ConectarBD();
        this.objetoVista.setVisible(true);

        this.objetoVista.getBtnBuscarRegistro().addActionListener(this);
        this.objetoVista.getBtnEliminarRegistro().addActionListener(this);
        this.objetoVista.getBtnModificarRegistro().addActionListener(this);
        this.objetoVista.getBtnNuevoRegistro().addActionListener(this);
        objetoVista.getTblPrincipal().setModel(new javax.swing.table.DefaultTableModel(new Object[][] { null }, null));
    }

    @Override
    public void actionPerformed(java.awt.event.ActionEvent e) {
        if (e.getSource() == objetoVista.getBtnNuevoRegistro()) {
            // Validar Campos
            try {
                String id = objetoVista.getTxtIdComprador().getText();
                String tipo = "";
                int numero = 0;
                double valor = 0;
                double valorRegistro = 0;

                if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 1) {
                    tipo = "Lote";
                } else if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 2) {
                    tipo = "Apto";
                } else if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 3) {
                    tipo = "Casa";
                } else {
                    // Error
                    JOptionPane.showMessageDialog(null, "Seleccione un tipo de inmueble");
                    System.out.println(objetoVista.getCbxTipoInmueble().getSelectedIndex());
                    return;
                }

                numero = Integer.parseInt(objetoVista.getTxtNumInmueble().getText());
                valor = Double.parseDouble(objetoVista.getTxtValorInmueble().getText());

                if (valor < 200000000) {
                    valorRegistro = valor * 0.01;
                } else {
                    valorRegistro = valor * 0.008;
                }

                String sql = "INSERT INTO inmuebles (codigo, tipo, numero, valor) VALUES (" + id + ", '" + tipo + "', "
                        + numero + ", " + valor + ")";
                objetoModelo.ingresar(sql);

            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }

        if (e.getSource() == objetoVista.getBtnBuscarRegistro()) {

            DefaultTableModel modelo = new DefaultTableModel(
                new Object[] { "Código", "Descripción", "Numero", "Valor", "Vr Registro" }, 0);
                
            // Totales
            double total1 = 0;
            double total08 = 0;
            try {
                String id = objetoVista.getTxtIdComprador().getText();
                if (!id.equals("")) {
                    String sql = "SELECT * FROM inmuebles WHERE codigo = " + id;
                    ResultSet rs = (ResultSet) objetoModelo.consulta(sql);

                    if (rs.next()) {
                        Object[] fila = new Object[5];
                        fila[0] = rs.getString("codigo");
                        fila[1] = rs.getString("tipo");
                        fila[2] = rs.getString("numero");
                        fila[3] = Double.parseDouble(rs.getString("valor"));
                        if (Double.parseDouble(fila[3].toString()) < 200000000) {
                            fila[4] = Double.parseDouble(fila[3].toString()) * 0.01;
                        } else {
                            fila[4] = Double.parseDouble(fila[3].toString()) * 0.008;
                        }
                        modelo.addRow(fila);
                        objetoVista.getTblPrincipal().setModel(modelo);

                    } else {
                        JOptionPane.showMessageDialog(null, "No se encontró el registro");
                    }
                } else {
                    String sql = "SELECT * FROM inmuebles";
                    ResultSet rs = (ResultSet) objetoModelo.consulta(sql);

                    while (rs.next()) {
                        Object[] fila = new Object[5];
                        fila[0] = rs.getString("codigo");
                        fila[1] = rs.getString("tipo");
                        fila[2] = rs.getString("numero");
                        fila[3] = rs.getString("valor").toString();
                        
                        if (Double.parseDouble(fila[3].toString()) < 200000000) {
                            fila[4] = Double.parseDouble(fila[3].toString()) * 0.01;
                            total1 = total1 + Double.parseDouble(fila[4].toString());
                        } else {
                            fila[4] = Double.parseDouble(fila[3].toString()) * 0.008;
                            total08 = total08 + Double.parseDouble(fila[4].toString());
                        }
                        modelo.addRow(fila);
                        objetoVista.getTblPrincipal().setModel(modelo);
                        objetoVista.getTxtTotalGastos08().setText(String.valueOf(total1));
                        objetoVista.getTxtTotalGastos1().setText(String.valueOf(total08));                        
                    }
                }
                
            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }

        if (e.getSource() == objetoVista.getBtnEliminarRegistro()) {
            try {
                String id = objetoVista.getTxtIdComprador().getText();
                String sql = "DELETE FROM inmuebles WHERE codigo = " + id;
                objetoModelo.ingresar(sql);
            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }
        
        if (e.getSource() == objetoVista.getBtnModificarRegistro()) {
            try {
                String id = objetoVista.getTxtIdComprador().getText();
                String tipo = "";
                int numero = 0;
                double valor = 0;
                double valorRegistro = 0;

                if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 1) {
                    tipo = "Lote";
                } else if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 2) {
                    tipo = "Apto";
                } else if (objetoVista.getCbxTipoInmueble().getSelectedIndex() == 3) {
                    tipo = "Casa";
                } else {
                    // Error
                    JOptionPane.showMessageDialog(null, "Seleccione un tipo de inmueble");
                    System.out.println(objetoVista.getCbxTipoInmueble().getSelectedIndex());
                    return;
                }

                numero = Integer.parseInt(objetoVista.getTxtNumInmueble().getText());
                valor = Double.parseDouble(objetoVista.getTxtValorInmueble().getText());

                if (valor < 200000000) {
                    valorRegistro = valor * 0.01;
                } else {
                    valorRegistro = valor * 0.008;
                }

                String sql = "UPDATE inmuebles SET tipo = '" + tipo + "', numero = " + numero + ", valor = " + valor
                        + " WHERE codigo = " + id;
                objetoModelo.ingresar(sql);

            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }


    }
}