import 'package:flutter/material.dart';
import 'package:clase63/models/models.dart';
import 'package:clase63/screens/screens.dart';

class AppRoutes {
  static const initialRoute = '/home';

  static final menuOptions = <MenuOption>[
    MenuOption(
      route: '/listview1',
      name: 'Listview 1',
      icon: Icons.list,
      screen: const Listview1Screen(),
    ),
    MenuOption(
      route: '/listview2',
      name: 'Listview 2',
      icon: Icons.list,
      screen: const Listview2Screen(),
    ),
    MenuOption(
      route: '/alert',
      name: 'Alert',
      icon: Icons.info,
      screen: const AlertScreen(),
    ),
    MenuOption(
      route: '/card',
      name: 'Card',
      icon: Icons.card_giftcard,
      screen: const CardScreen(),
    ),
    MenuOption(
      route: '/cards_notifications',
      name: 'Card Notifications',
      icon: Icons.notifications,
      screen: const CardsNotifications(),
    ),
    MenuOption(
      route: '/avatar',
      name: 'Circle Avatar',
      icon: Icons.account_circle,
      screen: const AvatarScreen(),
    ),
    MenuOption(
      route: '/animated',
      name: 'Animated',
      icon: Icons.animation,
      screen: const AnimatedScreen(),
    ),
    MenuOption(
      route: '/inputs',
      name: 'Inputs',
      icon: Icons.input,
      screen: const InputsScreen(),
    ),
    MenuOption(
      route: '/slider',
      name: 'Slider & Checks',
      icon: Icons.slideshow,
      screen: const SliderScreen(),
    ),
    MenuOption(
      route: '/listview_builder',
      name: 'Listview Builder',
      icon: Icons.list,
      screen: const ListViewBuilderScreen(),
    ),
  ];

  // get app rouutes
  static Map<String, Widget Function(BuildContext)> getAppRoutes() {
    var home = MenuOption(
      route: '/home',
      name: 'Home',
      icon: Icons.home,
      screen: const HomeScreen(),
    );
    Map<String, Widget Function(BuildContext)> appRoutes = {};
    //agregar home a la lista de rutas
    appRoutes[home.route] = (context) => home.screen;
    for (final option in menuOptions) {
      appRoutes.addAll({option.route: (BuildContext context) => option.screen});
    }
    return appRoutes;
  }

  // funcion que convierte un menu options en routes
  static Route onGenerateRoute(RouteSettings settings) {
    return MaterialPageRoute(
      builder: (context) => const HomeScreen(),
    );
  }
}
