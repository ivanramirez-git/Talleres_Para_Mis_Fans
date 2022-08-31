import 'package:clase63/widgets/widgets.dart';
import 'package:flutter/material.dart';

import '../data/datos_notifications.dart';

class CardNotifications extends StatelessWidget {
  const CardNotifications({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    var eventosNotificaciones = getEventos();
    return Scaffold(
      // appBar: AppBar(
      //   title: const Text('Tarjetas de Notificaciones'),
      // ),
      body: Padding(
        padding: const EdgeInsets.symmetric(vertical: 0, horizontal: 0),
        child: Column(
          children: [
            Container(
              height: 150,
              width: double.infinity,
              color: Colors.amber,
              child: const Center(child: Text('HEADER')),
            ),
            SizedBox(
              height: MediaQuery.of(context).size.height - 150,
              child: ListView(
                children: [
                  // CustonCardConnectNotifications(
                  //     title: 'Notificaciones',
                  //     dateTime: DateTime.now(),
                  //     isRead: true,
                  //     icon: Icons.message),
                  // const Divider(),
                  // CustonCardEvents(
                  //     dateTimeFrom: DateTime.now(),
                  //     dateTimeUntil:
                  //         DateTime.now().add(const Duration(hours: -3)),
                  //     title: 'E. Com',
                  //     isUserEvents: false,
                  //     icon: Icons.event,
                  //     link: const {
                  //       'url': 'https://www.google.com',
                  //       'text': 'Google',
                  //     },
                  //     notification: '5 minutes',
                  //     description: 'Lorem ipsum dolor sit amet'),
                  // const Divider(),
                  const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Center(child: Text('Notifications')),
                  ),
                  for (var evento in eventosNotificaciones['notifications'])
                    CustonCardConnectNotifications(
                      title: evento['title'],
                      dateTime: evento['dateTime'],
                      isRead: evento['isRead'],
                      icon: evento['icon'],
                    ),
                  const Divider(),
                  const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Center(child: Text('User Events')),
                  ),
                  /*
                  userEvents:
                    [
                      {
                        date: 2022-08-30 12:47:56.601727,
                        label: August 30, 2022,
                        events:
                          [
                            {
                              dateTimeUntil: 2022-08-30 14:47:56.601727,
                              dateTimeFrom: 2022-08-30 12:47:56.601727,
                              title: Evento 1,
                              isUserEvents: true,
                              icon: Icono de evento 1,
                              link: { url: https://www.google.com, text: Ir a Google },
                              notification: Notificación de evento 1,
                              description: Descripción de evento 1,
                            },
                          ],
                      },
                      {
                        date: 2022-08-27 22:47:56.601727,
                        label: August 27, 2022,
                        events:
                          [
                            {
                              dateTimeUntil: 2022-08-27 23:47:56.601727,
                              dateTimeFrom: 2022-08-27 22:47:56.601727,
                              title: Evento 3,
                              isUserEvents: true,
                              icon: Icono de evento 3,
                              link: { url: https://www.instagram.com, text: Ir a Instagram },
                              notification: Notificación de evento 3,
                              description: Descripción de evento 3,
                            },
                            {
                              dateTimeUntil: 2022-08-27 09:17:56.601727,
                              dateTimeFrom: 2022-08-27 07:17:56.601727,
                              title: Evento 4,
                              isUserEvents: true,
                              icon: Icono de evento 4,
                              link: { url: https://www.twitter.com, text: Ir a Twitter },
                              notification: Notificación de evento 4,
                              description: Descripción de evento 4,
                            },
                          ],
                      },
                    ],
                  */
                  for (var evento in eventosNotificaciones['userEvents'])
                    for (var eventoEvento in evento['events'])
                      CustonCardEvents(
                        dateTimeFrom: eventoEvento['dateTimeFrom'],
                        dateTimeUntil: eventoEvento['dateTimeUntil'],
                        title: eventoEvento['title'],
                        isUserEvents: eventoEvento['isUserEvents'],
                        icon: eventoEvento['icon'],
                        link: eventoEvento['link'],
                        notification: eventoEvento['notification'],
                        description: eventoEvento['description'],
                      ),

                  TextButton(
                    onPressed: () {},
                    child: const Text('Ver todas'),
                  ),
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}
