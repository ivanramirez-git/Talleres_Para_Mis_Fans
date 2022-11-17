/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vista;

import java.awt.Component;
import java.util.ArrayList;
import java.util.List;

import javax.swing.table.DefaultTableModel;

import modelo.Persona;
import modelo.Tablero;
import ticobingo.Estado;

/**
 *
 * @author nitro5
 */
public class Home extends javax.swing.JFrame {

    private Estado estado;
    private Persona[] personas;
    private Tablero[] tableros;
    private int contador;

    /**
     * Creates new form Home
     */
    public Home(Estado estado) {
        this.estado = estado;
        // solo 10 tableros solo 10 personas
        this.personas = new Persona[10];
        this.tableros = new Tablero[10];
        this.contador = 0;
        initComponents();
        // Dejar tabla en blanco
        jTable1.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][] {},
                new String[] {
                }));
        // Preparar 33 espacios, 3 columnas y 11 filas
        jTable1.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][] {
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null },
                        { null, null, null }
                },
                new String[] {
                }));
        // dar borde a cada celda
        jTable1.setShowGrid(true);

        // Bloquear boton 5
        jButton5.setEnabled(false);
        jButton2.setEnabled(false);
        jButton3.setEnabled(false);
        jButton1.setEnabled(false);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelHeader = new javax.swing.JPanel();
        jButton4 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel24 = new javax.swing.JLabel();
        txtBolita1 = new javax.swing.JTextField();
        panelBody1 = new javax.swing.JPanel();
        tablero1 = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        estado1 = new javax.swing.JTextField();
        cliente1 = new javax.swing.JButton();
        tablero3 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        estado3 = new javax.swing.JTextField();
        cliente3 = new javax.swing.JButton();
        tablero2 = new javax.swing.JPanel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        estado2 = new javax.swing.JTextField();
        cliente2 = new javax.swing.JButton();
        tablero5 = new javax.swing.JPanel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        estado5 = new javax.swing.JTextField();
        cliente5 = new javax.swing.JButton();
        tablero6 = new javax.swing.JPanel();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        estado6 = new javax.swing.JTextField();
        cliente6 = new javax.swing.JButton();
        tablero7 = new javax.swing.JPanel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        estado7 = new javax.swing.JTextField();
        cliente7 = new javax.swing.JButton();
        tablero4 = new javax.swing.JPanel();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        estado4 = new javax.swing.JTextField();
        cliente4 = new javax.swing.JButton();
        tablero8 = new javax.swing.JPanel();
        jLabel17 = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        estadi8 = new javax.swing.JTextField();
        cliente8 = new javax.swing.JButton();
        tablero10 = new javax.swing.JPanel();
        jLabel19 = new javax.swing.JLabel();
        jLabel20 = new javax.swing.JLabel();
        estado10 = new javax.swing.JTextField();
        cliente10 = new javax.swing.JButton();
        tablero9 = new javax.swing.JPanel();
        jLabel21 = new javax.swing.JLabel();
        jLabel22 = new javax.swing.JLabel();
        estado9 = new javax.swing.JTextField();
        cliente9 = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jTable1 = new javax.swing.JTable();
        menuBar = new javax.swing.JMenuBar();
        menuArchivo = new javax.swing.JMenu();
        menuItemAbrir = new javax.swing.JMenuItem();
        menuItemGuardar = new javax.swing.JMenuItem();
        menuTicobingo = new javax.swing.JMenu();
        menuItemNuevoJuego = new javax.swing.JMenuItem();
        menuItemGenerarCartones = new javax.swing.JMenuItem();
        menuItemVenderCartones = new javax.swing.JMenuItem();
        menuItemComenzarBingo = new javax.swing.JMenuItem();
        menuAyuda = new javax.swing.JMenu();
        menuItemAcercaDe = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        panelHeader.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jButton4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/Nuevo Juego.png"))); // NOI18N
        jButton4.setText("Nuevo Juego");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        panelHeader.add(jButton4, new org.netbeans.lib.awtextra.AbsoluteConstraints(125, 0, -1, -1));

        jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/Generar Cartones.png"))); // NOI18N
        jButton3.setText("Generar Cartones");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        panelHeader.add(jButton3, new org.netbeans.lib.awtextra.AbsoluteConstraints(300, 0, -1, -1));

        jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/Vender Cartones.png"))); // NOI18N
        jButton2.setText("Vender Cartones");
        panelHeader.add(jButton2, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 0, -1, -1));

        jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/Comenzar Bingo.jpg"))); // NOI18N
        jButton1.setText("Comenzar Bingo");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        panelHeader.add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(690, 0, -1, -1));

        jButton5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/Nueva Bolita.png"))); // NOI18N
        jButton5.setText("Nueva Bolita");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });
        panelHeader.add(jButton5, new org.netbeans.lib.awtextra.AbsoluteConstraints(1080, 0, -1, -1));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/Iconos/ticobingo.PNG"))); // NOI18N
        jLabel2.setAlignmentY(0.0F);
        panelHeader.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 20, -1, -1));

        jLabel24.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel24.setForeground(new java.awt.Color(204, 51, 255));
        jLabel24.setText("BOLITA N°");
        panelHeader.add(jLabel24, new org.netbeans.lib.awtextra.AbsoluteConstraints(890, 30, -1, -1));

        txtBolita1.setEditable(false);
        txtBolita1.setFont(new java.awt.Font("Tahoma", 1, 28)); // NOI18N
        txtBolita1.setForeground(new java.awt.Color(255, 0, 102));
        txtBolita1.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        panelHeader.add(txtBolita1, new org.netbeans.lib.awtextra.AbsoluteConstraints(990, 20, 71, 48));

        getContentPane().add(panelHeader, new org.netbeans.lib.awtextra.AbsoluteConstraints(4, 1, 1250, 80));

        panelBody1.setBorder(new javax.swing.border.MatteBorder(null));
        panelBody1.setAlignmentX(0.0F);
        panelBody1.setAlignmentY(0.0F);
        panelBody1.setPreferredSize(new java.awt.Dimension(1000, 450));

        tablero1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel5.setText("Carton No 1");
        tablero1.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel6.setText("Estado:");
        tablero1.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado1.setEditable(false);
        estado1.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado1.setForeground(new java.awt.Color(51, 51, 255));
        estado1.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado1.setText("DISPONIBLE");
        tablero1.add(estado1, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente1.setText("Datos del Cliente");
        tablero1.add(cliente1, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero3.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero3.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel3.setText("Carton No 3");
        tablero3.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel4.setText("Estado:");
        tablero3.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado3.setEditable(false);
        estado3.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado3.setForeground(new java.awt.Color(51, 51, 255));
        estado3.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado3.setText("DISPONIBLE");
        tablero3.add(estado3, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente3.setText("Datos del Cliente");
        tablero3.add(cliente3, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero2.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero2.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel7.setText("Carton No 2");
        tablero2.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel8.setText("Estado:");
        tablero2.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado2.setEditable(false);
        estado2.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado2.setForeground(new java.awt.Color(51, 51, 255));
        estado2.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado2.setText("DISPONIBLE");
        tablero2.add(estado2, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente2.setText("Datos del Cliente");
        tablero2.add(cliente2, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero5.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero5.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel9.setText("Carton No 5");
        tablero5.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel10.setText("Estado:");
        tablero5.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado5.setEditable(false);
        estado5.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado5.setForeground(new java.awt.Color(51, 51, 255));
        estado5.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado5.setText("DISPONIBLE");
        tablero5.add(estado5, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente5.setText("Datos del Cliente");
        tablero5.add(cliente5, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero6.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero6.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel11.setText("Carton No 6");
        tablero6.add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel12.setText("Estado:");
        tablero6.add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado6.setEditable(false);
        estado6.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado6.setForeground(new java.awt.Color(51, 51, 255));
        estado6.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado6.setText("DISPONIBLE");
        tablero6.add(estado6, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente6.setText("Datos del Cliente");
        tablero6.add(cliente6, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero7.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero7.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel13.setText("Carton No 7");
        tablero7.add(jLabel13, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel14.setText("Estado:");
        tablero7.add(jLabel14, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado7.setEditable(false);
        estado7.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado7.setForeground(new java.awt.Color(51, 51, 255));
        estado7.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado7.setText("DISPONIBLE");
        tablero7.add(estado7, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente7.setText("Datos del Cliente");
        tablero7.add(cliente7, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero4.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero4.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel15.setText("Carton No 4");
        tablero4.add(jLabel15, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel16.setText("Estado:");
        tablero4.add(jLabel16, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado4.setEditable(false);
        estado4.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado4.setForeground(new java.awt.Color(51, 51, 255));
        estado4.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado4.setText("DISPONIBLE");
        tablero4.add(estado4, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente4.setText("Datos del Cliente");
        tablero4.add(cliente4, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero8.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero8.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel17.setText("Carton No 8");
        tablero8.add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel18.setText("Estado:");
        tablero8.add(jLabel18, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estadi8.setEditable(false);
        estadi8.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estadi8.setForeground(new java.awt.Color(51, 51, 255));
        estadi8.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estadi8.setText("DISPONIBLE");
        tablero8.add(estadi8, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente8.setText("Datos del Cliente");
        tablero8.add(cliente8, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero10.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero10.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel19.setText("Carton No 10");
        tablero10.add(jLabel19, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel20.setText("Estado:");
        tablero10.add(jLabel20, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado10.setEditable(false);
        estado10.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado10.setForeground(new java.awt.Color(51, 51, 255));
        estado10.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado10.setText("DISPONIBLE");
        tablero10.add(estado10, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente10.setText("Datos del Cliente");
        tablero10.add(cliente10, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        tablero9.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        tablero9.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel21.setText("Carton No 9");
        tablero9.add(jLabel21, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, -1, -1));

        jLabel22.setText("Estado:");
        tablero9.add(jLabel22, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 230, -1, -1));

        estado9.setEditable(false);
        estado9.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        estado9.setForeground(new java.awt.Color(51, 51, 255));
        estado9.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        estado9.setText("DISPONIBLE");
        tablero9.add(estado9, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 80, 20));

        cliente9.setText("Datos del Cliente");
        tablero9.add(cliente9, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 250, -1, -1));

        javax.swing.GroupLayout panelBody1Layout = new javax.swing.GroupLayout(panelBody1);
        panelBody1.setLayout(panelBody1Layout);
        panelBody1Layout.setHorizontalGroup(
            panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelBody1Layout.createSequentialGroup()
                .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(panelBody1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(tablero5, javax.swing.GroupLayout.DEFAULT_SIZE, 260, Short.MAX_VALUE)
                            .addComponent(tablero1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(tablero2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(tablero6, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(panelBody1Layout.createSequentialGroup()
                                .addComponent(tablero7, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tablero8, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(panelBody1Layout.createSequentialGroup()
                                .addComponent(tablero3, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tablero4, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, panelBody1Layout.createSequentialGroup()
                        .addGap(203, 203, 203)
                        .addComponent(tablero9, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(144, 144, 144)
                        .addComponent(tablero10, javax.swing.GroupLayout.PREFERRED_SIZE, 260, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        panelBody1Layout.setVerticalGroup(
            panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelBody1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(tablero3, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero2, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero1, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero4, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(tablero5, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero6, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero7, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero8, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(panelBody1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(tablero10, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tablero9, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        getContentPane().add(panelBody1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 90, 1070, 860));

        jPanel1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        jLabel1.setText("Numeros Jugados");

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(49, 49, 49)
                .addComponent(jLabel1))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(4, 4, 4)
                .addComponent(jTable1, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(9, 9, 9)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jTable1, javax.swing.GroupLayout.PREFERRED_SIZE, 587, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(4, 4, 4))
        );

        getContentPane().add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(1070, 90, 190, 630));

        menuArchivo.setText("Archivo");

        menuItemAbrir.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_A, 0));
        menuItemAbrir.setText("Abrir");
        menuArchivo.add(menuItemAbrir);

        menuItemGuardar.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_G, 0));
        menuItemGuardar.setText("Guardar");
        menuArchivo.add(menuItemGuardar);

        menuBar.add(menuArchivo);

        menuTicobingo.setText("TicoBingo");

        menuItemNuevoJuego.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, 0));
        menuItemNuevoJuego.setText("Nuevo Juego");
        menuTicobingo.add(menuItemNuevoJuego);

        menuItemGenerarCartones.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_G, 0));
        menuItemGenerarCartones.setText("Generar Cartones");
        menuTicobingo.add(menuItemGenerarCartones);

        menuItemVenderCartones.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_V, 0));
        menuItemVenderCartones.setText("Vender Cartones");
        menuTicobingo.add(menuItemVenderCartones);

        menuItemComenzarBingo.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_C, 0));
        menuItemComenzarBingo.setText("Comenzar Bingo");
        menuTicobingo.add(menuItemComenzarBingo);

        menuBar.add(menuTicobingo);

        menuAyuda.setText("Ayuda");

        menuItemAcercaDe.setText("Acerca de");
        menuAyuda.add(menuItemAcercaDe);

        menuBar.add(menuAyuda);

        setJMenuBar(menuBar);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:

    }// GEN-LAST:event_jButton1ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][] {
                        { null }
                },
                new String[] {
                }));

        // limpiar estado
        estado.clear();
        // inicializar 10 tableros
        for (int i = 0; i < 10; i++) {
            tableros[i] = new Tablero(i, estado);
        }
        // Bloquear boton 5
        jButton3.setEnabled(true);

    }// GEN-LAST:event_jButton4ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        // TODO add your handling code here:
        // agregar los tableros a los paneles -> tablero1, tablero2, tablero3, tablero4, tablero5, ... , tablero10
        for (int i = 0; i < 10; i++) {
            switch (i) {
            case 0:
                tablero1.add(tableros[i].getPanel());
                break;
            case 1:
                tablero2.add(tableros[i].getPanel());
                break;
            case 2:
                tablero3.add(tableros[i].getPanel());
                break;
            case 3:
                tablero4.add(tableros[i].getPanel());
                break;
            case 4:
                tablero5.add(tableros[i].getPanel());
                break;
            case 5:
                tablero6.add(tableros[i].getPanel());
                break;
            case 6:
                tablero7.add(tableros[i].getPanel());
                break;
            case 7:
                tablero8.add(tableros[i].getPanel());
                break;
            case 8:
                tablero9.add(tableros[i].getPanel());
                break;
            case 9:
                tablero10.add(tableros[i].getPanel());
                break;
            }
            
        }
        
    }//GEN-LAST:event_jButton3ActionPerformed

    // Funcion para generar un numero aleatorio entre min y max
    public int generarNumeroAleatorio(int min, int max) {
        return (int) (Math.random() * (max - min + 1) + min);
    }

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_jButton5ActionPerformed
        // TODO add your handling code here:
        // Logica del la bolita

        int numero = 0;
        // imprimir estado
        System.out.println(this.estado.containsKey("historyNumbers"));
        if (!this.estado.containsKey("historyNumbers")) {
            numero = generarNumeroAleatorio(1, 75);

            List<Integer> historyNumbers = new ArrayList<Integer>();
            historyNumbers.add(numero);
            this.estado.set("historyNumbers", historyNumbers);
            this.estado.set("currentNumber", numero);
        } else {

            try {
                do {
                    numero = generarNumeroAleatorio(1, 75);
                } while (((List<Integer>) this.estado.get("historyNumbers")).contains(numero));
                List<Integer> historyNumbers = (List<Integer>) this.estado.get("historyNumbers");
                historyNumbers.add(numero);
                this.estado.set("historyNumbers", historyNumbers);
                this.estado.set("currentNumber", numero);
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        // actualizar el txtBolita
        txtBolita1.setText(String.valueOf(numero));
        // actualizar la tabla
        updateTable();
        // imprimir estado
        System.out.println(this.estado);
        // esperar 1 segundo
        try {
            // desactivar boton
            jButton5.setEnabled(false);
            // colocar el fondo del boton en rojo
            Thread.sleep(1000);
            // activar boton
            jButton5.setEnabled(true);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }// GEN-LAST:event_jButton5ActionPerformed

    // Actualizar tabla con los datos que esten en el estado.historyNumbers
    private void updateTable() {

        // obtener los numeros que ya salieron
        List<Integer> historyNumbers = (List<Integer>) this.estado.get("historyNumbers");
        int size = historyNumbers.size();
        // crear un arreglo de objetos
        Object[][] data = new Object[size][1];
        // llenar el arreglo con los numeros que ya salieron
        for (int i = 0; i < size; i++) {
            data[i][0] = historyNumbers.get(i);
        }
        // crear un arreglo de strings
        String[] columnNames = { "Numeros" };
        // crear un modelo de tabla
        DefaultTableModel model = new DefaultTableModel(data, columnNames);
        // asignar el modelo a la tabla
        jTable1.setModel(model);

    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton cliente1;
    private javax.swing.JButton cliente10;
    private javax.swing.JButton cliente2;
    private javax.swing.JButton cliente3;
    private javax.swing.JButton cliente4;
    private javax.swing.JButton cliente5;
    private javax.swing.JButton cliente6;
    private javax.swing.JButton cliente7;
    private javax.swing.JButton cliente8;
    private javax.swing.JButton cliente9;
    private javax.swing.JTextField estadi8;
    private javax.swing.JTextField estado1;
    private javax.swing.JTextField estado10;
    private javax.swing.JTextField estado2;
    private javax.swing.JTextField estado3;
    private javax.swing.JTextField estado4;
    private javax.swing.JTextField estado5;
    private javax.swing.JTextField estado6;
    private javax.swing.JTextField estado7;
    private javax.swing.JTextField estado9;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel20;
    private javax.swing.JLabel jLabel21;
    private javax.swing.JLabel jLabel22;
    private javax.swing.JLabel jLabel24;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTable jTable1;
    private javax.swing.JMenu menuArchivo;
    private javax.swing.JMenu menuAyuda;
    private javax.swing.JMenuBar menuBar;
    private javax.swing.JMenuItem menuItemAbrir;
    private javax.swing.JMenuItem menuItemAcercaDe;
    private javax.swing.JMenuItem menuItemComenzarBingo;
    private javax.swing.JMenuItem menuItemGenerarCartones;
    private javax.swing.JMenuItem menuItemGuardar;
    private javax.swing.JMenuItem menuItemNuevoJuego;
    private javax.swing.JMenuItem menuItemVenderCartones;
    private javax.swing.JMenu menuTicobingo;
    private javax.swing.JPanel panelBody1;
    private javax.swing.JPanel panelHeader;
    private javax.swing.JPanel tablero1;
    private javax.swing.JPanel tablero10;
    private javax.swing.JPanel tablero2;
    private javax.swing.JPanel tablero3;
    private javax.swing.JPanel tablero4;
    private javax.swing.JPanel tablero5;
    private javax.swing.JPanel tablero6;
    private javax.swing.JPanel tablero7;
    private javax.swing.JPanel tablero8;
    private javax.swing.JPanel tablero9;
    private javax.swing.JTextField txtBolita1;
    // End of variables declaration//GEN-END:variables

}
