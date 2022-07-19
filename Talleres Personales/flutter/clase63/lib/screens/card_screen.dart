import 'package:flutter/material.dart';
import 'package:clase63/widgets/widgets.dart';

class CardScreen extends StatelessWidget {
  const CardScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Card'),
      ),
      body: ListView(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
        children: const <Widget>[
          CustomCardType1(),
          SizedBox(height: 10),
          CustomCardType2(
              imageUrl:
                  'https://img-s-msn-com.akamaized.net/tenant/amp/entityid/AAYTfOC.img?h=416&w=799&m=6&q=60&u=t&o=f&l=f&x=523&y=584'),
        ],
      ),
    );
  }
}
