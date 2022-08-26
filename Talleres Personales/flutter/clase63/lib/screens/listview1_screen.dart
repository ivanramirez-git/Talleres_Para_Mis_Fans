import 'package:clase63/themes/app_theme.dart';
import 'package:flutter/material.dart';

class Listview1Screen extends StatelessWidget {
  const Listview1Screen({Key? key}) : super(key: key);

  final options = const [
    'Bogota',
    'Medellin',
    'Cali',
    'Barranquilla',
    'Cartagena',
    'Bucaramanga',
    'Cucuta',
    'Pereira',
    'Armenia',
    'Manizales',
    'Valledupar',
    'Monteria',
    'Pasto',
    'Villavicencio',
    'Tunja',
    'Neiva',
    'Popayán',
    'Arauca',
    'Ibague',
    'Tame',
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Listview 1 Screen'),
      ),
      body: ListView.separated(
        itemCount: options.length,
        itemBuilder: (context, index) => ListTile(
          title: Text(options[index]),
          trailing: const Icon(Icons.arrow_forward_ios),
          onTap: () {
            final team = options[index];
            debugPrint('$team tapped');
          },
        ),
        separatorBuilder: (_, __) => const Divider(
          height: 1.4,
        ),
      ),
    );
  }
}
