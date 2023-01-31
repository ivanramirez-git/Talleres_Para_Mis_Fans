import 'dart:io';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

import 'package:flutter/foundation.dart';

class AlertScreen extends StatelessWidget {
  const AlertScreen({Key? key}) : super(key: key);

  void displayDialog(BuildContext context) {
    showDialog(
      barrierDismissible: false,
      context: context,
      builder: (context) => AlertDialog(
        elevation: 5,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(10),
        ),
        title: const Text('Alert Dialog'),
        content: Column(
          mainAxisSize: MainAxisSize.min,
          children: const <Widget>[
            Text('Este es el contenido de la alerta.'),
            SizedBox(height: 10),
            FlutterLogo(size: 50),
          ],
        ),
        actions: [
          TextButton(
            onPressed: () {
              Navigator.of(context).pop();
            },
            child: const Text('Cancelar'),
          ),
        ],
      ),
    );
  }

  void displayDialogIOS(BuildContext context) {
    showCupertinoDialog(
      context: context,
      barrierDismissible: true,
      builder: (context) => CupertinoAlertDialog(
        title: const Text('Alert Dialog'),
        content: Column(
          mainAxisSize: MainAxisSize.min,
          children: const <Widget>[
            Text('Este es el contenido de la alerta.'),
            SizedBox(height: 10),
            FlutterLogo(size: 50),
          ],
        ),
        actions: [
          CupertinoDialogAction(
            child: const Text('Cancelar'),
            onPressed: () {
              Navigator.of(context).pop();
            },
          ),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            debugPrint('Alerta');
            if (defaultTargetPlatform == TargetPlatform.iOS) {
              displayDialogIOS(context);
            } else {
              displayDialog(context);
            }
          },
          child: const Text('Alerta'),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.of(context).pop();
        },
        child: const Icon(Icons.close),
      ),
    );
  }
}
