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

                  const Divider(),
                  /*
                  communityEvents:
                    [
                      {
                        date: 2022-08-30 11:17:56.601727,
                        label: August 30, 2022,
                        events:
                          [
                            {
                              dateTimeUntil: 2022-08-30 13:17:56.601727,
                              dateTimeFrom: 2022-08-30 11:17:56.601727,
                              isUserEvents: false,
                              icon: Icono de evento 5,
                              link: { url: https://www.youtube.com, text: Ir a Youtube },
                              notification: Notificación de evento 5,
                              description: Descripción de evento 5,
                            },
                            {
                              dateTimeUntil: 2022-08-30 13:17:56.601727,
                              dateTimeFrom: 2022-08-30 10:17:56.601727,
                              isUserEvents: false,
                              icon: Icono de evento 6,
                              link: { url: https://www.espn.com, text: Ir a Espn },
                              notification: Notificación de evento 5,
                              description: Descripción de evento 5,
                            },
                          ],
                      },
                      {
                        date: 2022-08-29 13:47:56.601727,
                        label: August 29, 2022,
                        events:
                          [
                            {
                              dateTimeUntil: 2022-08-29 14:47:56.601727,
                              dateTimeFrom: 2022-08-29 13:47:56.601727,
                              title: Evento 2,
                              isUserEvents: false,
                              icon: Icono de evento 2,
                              link: { url: https://www.facebook.com, text: Ir a Facebook },
                              notification: Notificación de evento 2,
                              description: Descripción de evento 2,
                            },
                          ],
                      },
                    ],

                  */

                  const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Center(child: Text('Community Events')),
                  ),
                  for (var evento in eventosNotificaciones['communityEvents'])
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
