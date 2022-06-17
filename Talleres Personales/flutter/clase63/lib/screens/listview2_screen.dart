import 'package:flutter/material.dart';

class Listview2Screen extends StatelessWidget {
  const Listview2Screen({Key? key}) : super(key: key);

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
        title: const Text('Listview 2 Screen'),
      ),
      body: ListView.separated(
        itemCount: options.length,
        itemBuilder: (context, index) => ListTile(
          title: Text(options[index]),
          trailing: const Icon(Icons.arrow_forward_ios),
          onTap: () {
            final team = options[index];
            print('$team tapped');
          },
        ),
        separatorBuilder: (_, __) => const Divider(
          height: 3,
          color: Colors.black,
        ),
      ),
    );
  }
}
