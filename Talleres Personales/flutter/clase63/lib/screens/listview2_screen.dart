import 'package:flutter/material.dart';

import '../data/constants.dart';

class Listview2Screen extends StatelessWidget {
  const Listview2Screen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    const options = constEquipos;
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
