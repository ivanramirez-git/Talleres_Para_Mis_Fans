// Paquetes de Flutter
import 'package:flutter/material.dart';

// Paquetes de terceros

// Paquetes de propios
import 'package:clase43_contador_hola_mundo/screens/counter_screen.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
        debugShowCheckedModeBanner: false, home: CounterScreen());
  }
}
