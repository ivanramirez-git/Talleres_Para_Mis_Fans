import 'package:flutter/material.dart';

class AppTheme {
  // Font
  static const String fontName = 'Roboto'; // Text App
  static const String fontNameBold = 'Roboto-Bold'; // App Bar

  // Color Primario
  static const Color primaryColor = Colors.teal;
  static const Color primaryColorDark = Color.fromARGB(255, 53, 0, 44);
  // Theme Light
  static final ThemeData lightTheme = ThemeData.light().copyWith(
    // Color Primario
    primaryColor: primaryColor,
    appBarTheme: const AppBarTheme(
      color: primaryColor,
      elevation: 0,
    ),
    // TextButton Theme
    textButtonTheme: TextButtonThemeData(
      style: TextButton.styleFrom(
        primary: primaryColor,
      ),
    ),
    // FloatingActionButton Theme
    floatingActionButtonTheme: const FloatingActionButtonThemeData(
      backgroundColor: primaryColor,
    ),
    // ElevatedButton Theme
    elevatedButtonTheme: ElevatedButtonThemeData(
      style: ElevatedButton.styleFrom(
        primary: primaryColor,
      ),
    ),
    // Divider Theme
    dividerTheme: const DividerThemeData(
      color: Colors.black,
    ),

    inputDecorationTheme: const InputDecorationTheme(
      floatingLabelStyle: TextStyle(
        color: primaryColor,
      ),
      enabledBorder: OutlineInputBorder(
        borderSide: BorderSide(
          color: primaryColor,
        ),
        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(10), topRight: Radius.circular(10)),
      ),
      focusedBorder: OutlineInputBorder(
        borderSide: BorderSide(
          color: primaryColor,
        ),
        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(10), topRight: Radius.circular(10)),
      ),
      border: OutlineInputBorder(
        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(10), topRight: Radius.circular(10)),
      ),
    ),
  );

  // Theme Dark
  static final ThemeData darkTheme = ThemeData.dark().copyWith(
    // Color Primario
    primaryColor: primaryColorDark,
    appBarTheme: const AppBarTheme(
      color: primaryColorDark,
      elevation: 0,
    ),
    // TextButton Theme
    textButtonTheme: TextButtonThemeData(
      style: TextButton.styleFrom(
        primary: primaryColorDark,
      ),
    ),
    // FloatingActionButton Theme
    floatingActionButtonTheme: const FloatingActionButtonThemeData(
      backgroundColor: primaryColorDark,
    ),
    // ElevatedButton Theme
    elevatedButtonTheme: ElevatedButtonThemeData(
      style: ElevatedButton.styleFrom(
        primary: primaryColorDark,
        shape: const StadiumBorder(),
        elevation: 0,
      ),
    ),
    // Divider Theme
    dividerTheme: const DividerThemeData(
      color: Colors.white,
    ),
  );
}
