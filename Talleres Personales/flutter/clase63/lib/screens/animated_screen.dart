import 'dart:async';
import 'dart:math';

import 'package:flutter/material.dart';

class AnimatedScreen extends StatefulWidget {
  const AnimatedScreen({Key? key}) : super(key: key);

  @override
  State<AnimatedScreen> createState() => _AnimatedScreenState();
}

class _AnimatedScreenState extends State<AnimatedScreen> {
  double _width = 110;
  double _height = 110;
  Color _color = Colors.red;
  BorderRadiusGeometry _borderRadius = BorderRadius.circular(50);
  bool _isActive = true;
  Timer? _timer;

  void changeShape() {
    if (_isActive) {
      // Timer 10 veces de 1 segundo
      _timer = Timer.periodic(const Duration(seconds: 1), (timer) {
        setState(() {
          // aleatoriamente cambiar el tamaño de la forma
          _width = Random().nextInt(1000).toDouble();
          _height = Random().nextInt(1000).toDouble();
          // aleatoriamente cambiar el color de la forma
          _color = Color.fromRGBO(
            Random().nextInt(255),
            Random().nextInt(255),
            Random().nextInt(255),
            1,
          );
          // aleatoriamente cambiar el borde de la forma
          _borderRadius =
              BorderRadius.circular(Random().nextInt(100).toDouble() + 10);
        });
      });
    } else {
      _timer?.cancel();
    }
    _isActive = !_isActive;
  }

  @override
  void dispose() {
    if (_timer != null) {
      _timer?.cancel();
    }
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Animated'),
      ),
      body: Center(
          child: InkWell(
        onTap: changeShape,
        splashColor: Colors.transparent,
        child: AnimatedContainer(
          duration: const Duration(milliseconds: 400),
          curve: Curves.easeInOut,
          width: _width,
          height: _height,
          decoration: BoxDecoration(
            borderRadius: _borderRadius,
            color: _color,
          ),
        ),
      )),
    );
  }
}
