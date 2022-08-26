import 'package:flutter/material.dart';
import 'package:clase63/widgets/widgets.dart';

class CardScreen extends StatelessWidget {
  const CardScreen({Key? key}) : super(key: key);
  final options = const [
    {
      'name': 'Alaves',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/alaves.png'
    },
    {
      'name': 'Athletic Bilbao',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/athleticbilbao.png'
    },
    {
      'name': 'Atletico de Madrid',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/atleticodemadrid.png'
    },
    {
      'name': 'Barcelona',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/barcelona.png'
    },
    {
      'name': 'Celta',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/celta.png'
    },
    {
      'name': 'Deportivo',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/deportivo.png'
    },
    {
      'name': 'Eibar',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/eibar.png'
    },
    {
      'name': 'Espanyol',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/espanyol.png'
    },
    {
      'name': 'Getafe',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/getafe.png'
    },
    {
      'name': 'Girona',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/girona.png'
    },
    {
      'name': 'Las Palmas',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/laspalmas.png'
    },
    {
      'name': 'Leganes',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/leganes.png'
    },
    {
      'name': 'Levante',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/levante.png'
    },
    {
      'name': 'Malaga',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/malaga.png'
    },
    {
      'name': 'Real Betis',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/realbetis.png'
    },
    {
      'name': 'Real Madrid',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/realmadrid.png'
    },
    {
      'name': 'Real Sociedad',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/realsociedad.png'
    },
    {
      'name': 'Valencia',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/valencia.png'
    },
    {
      'name': 'Villarreal',
      'image':
          'https://raw.githubusercontent.com/mbcorona/LigaMexicanaJson/master/imgs/Liga_Espanola/villarreal.png'
    }
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Card'),
      ),
      body: ListView(
        padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
        children: <Widget>[
          for (final option in options)
            CustomCardType2(
              imageUrl: option['image'] ?? '',
              title: option['name'] ?? '',
            ),
        ],
      ),
    );
  }
}
