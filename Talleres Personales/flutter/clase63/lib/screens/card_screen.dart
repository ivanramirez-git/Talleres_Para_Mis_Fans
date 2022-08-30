import 'package:flutter/material.dart';
import 'package:clase63/widgets/widgets.dart';

import '../data/constants.dart';

class CardScreen extends StatelessWidget {
  const CardScreen({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    var teams = constTeams;
    return Scaffold(
      appBar: AppBar(
        title: const Text('Card'),
      ),
      body: ListView(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
        children: <Widget>[
          for (final option in teams)
            CustomCardType2(
              imageUrl: option['image'] ?? '',
              title: option['name'] ?? '',
            ),
        ],
      ),
    );
  }
}
