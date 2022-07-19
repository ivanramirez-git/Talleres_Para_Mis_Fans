import 'package:flutter/material.dart';

class AppTheme {
  // Font
  static const String fontName = 'Roboto'; // Text App
  static const String fontNameBold = 'Roboto-Bold'; // App Bar

  // Color Primario
  static const Color primaryColor = Colors.red;

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
      ));

  // Theme Dark
  static final ThemeData darkTheme = ThemeData.dark().copyWith(
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
      ));
}
