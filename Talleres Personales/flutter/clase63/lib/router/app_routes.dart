import 'package:flutter/material.dart';
import 'package:clase63/models/models.dart';
import 'package:clase63/screens/screens.dart';

class AppRoutes {
  static const initialRoute = 'home';

  static final menuOptions = <MenuOption>[
    MenuOption(
      route: 'home',
      name: 'Home',
      icon: Icons.home,
      screen: const HomeScreen(),
    ),
    MenuOption(
      route: 'listview1',
      name: 'Listview 1',
      icon: Icons.list,
      screen: const Listview1Screen(),
    ),
    MenuOption(
      route: 'listview2',
      name: 'Listview 2',
      icon: Icons.list,
      screen: const Listview2Screen(),
    ),
    MenuOption(
      route: 'alert',
      name: 'Alert',
      icon: Icons.info,
      screen: const AlertScreen(),
    ),
    MenuOption(
      route: 'card',
      name: 'Card',
      icon: Icons.card_giftcard,
      screen: const CardScreen(),
    ),
  ];

  // get app rouutes
  static Map<String, Widget Function(BuildContext)> getAppRoutes() {
    Map<String, Widget Function(BuildContext)> appRoutes = {};
    for (final option in menuOptions) {
      appRoutes.addAll({option.route: (BuildContext context) => option.screen});
    }
    return appRoutes;
  }

  // funcion que convierte un menu options en routes
  static Route onGenerateRoute(RouteSettings settings) {
    return MaterialPageRoute(
      builder: (context) => const AlertScreen(),
    );
  }
}
