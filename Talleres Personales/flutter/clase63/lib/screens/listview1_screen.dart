import 'package:flutter/material.dart';

class Listview1Screen extends StatelessWidget {
  const Listview1Screen({Key? key}) : super(key: key);

  final options = const [
    'Valencia FC',
    'Sevilla FC',
    'Atletic Club Bilbao',
    'FC Barcelona',
    'Real Madrid',
    'Real Sociedad',
    'Villarreal CF',
    'Athletico Madrid',
    'Real Betis',
    'Real Valladolid',
    'Espanyol',
    'Girona FC',
    'SD Eibar'
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Listview 1 Screen'),
      ),
      body: ListView(
        children: [
          ...options.map((option) {
            return ListTile(
              title: Text(option),
              trailing: const Icon(Icons.arrow_forward_ios),
            );
          }).toList()
        ],
      ),
    );
  }
}
