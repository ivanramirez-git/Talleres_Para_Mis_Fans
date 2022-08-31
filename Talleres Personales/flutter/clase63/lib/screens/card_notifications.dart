import 'package:clase63/widgets/widgets.dart';
import 'package:flutter/material.dart';

class CardNotifications extends StatelessWidget {
  const CardNotifications({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Tarjetas de Notificaciones'),
      ),
      body: Padding(
        padding: const EdgeInsets.symmetric(vertical: 30, horizontal: 20),
        child: Column(
          children: [
            CustonCardConnectNotifications(
                title: 'Notificaciones',
                dateTime: DateTime.now(),
                isRead: true,
                icon: Icons.message),
            const Divider(),
            CustonCardConnectNotifications(
              title: 'Notificaciones',
              dateTime: DateTime.now(),
              isRead: false,
              icon: Icons.call,
            ),
            const Divider(),
            CustonCardEvents(
                dateTimeFrom: DateTime.now(),
                dateTimeUntil: DateTime.now().add(const Duration(hours: -3)),
                title: 'E. Com',
                isUserEvents: false,
                icon: Icons.event,
                link: const {
                  'url': 'https://www.google.com',
                  'text': 'Google',
                },
                notification: '5 minutes',
                description: 'Lorem ipsum dolor sit amet'
                ),
            const Divider(),
            CustonCardEvents(
                dateTimeFrom: DateTime.now(),
                dateTimeUntil: DateTime.now().add(const Duration(hours: -3)),
                title: 'E. Usu',
                isUserEvents: true,
                icon: Icons.event,
                link: const {
                  'url': 'https://www.google.com',
                  'text': 'Google',
                },
                notification: '5 minutes',
                description: 'Lorem ipsum dolor sit amet'),
            const Divider(),
          ],
        ),
      ),
    );
  }
}
