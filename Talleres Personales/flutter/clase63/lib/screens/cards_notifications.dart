// import 'dart:html';

import 'package:clase63/widgets/widgets.dart';
import 'package:flutter/material.dart';

import '../data/datos_notifications.dart';

class CardsNotifications extends StatelessWidget {
  const CardsNotifications({Key? key}) : super(key: key);

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
            InkWell(
              onTap: () {
                Navigator.pop(context);
              },
              child: Container(
                height: 150,
                width: double.infinity,
                color: Colors.blue,
                child: const Center(child: Text('HEADER')),
              ),
            ),
            SizedBox(
              height: MediaQuery.of(context).size.height - 150,
              child: ListView(
                children: [
                  const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Center(child: Text('Notifications')),
                  ),
                  for (var evento in eventosNotificaciones['notifications'])
                    CustomCardConnectNotifications(
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
                    ListCardEvents(evento),
                  const Divider(),
                  const Padding(
                    padding: EdgeInsets.all(8.0),
                    child: Center(child: Text('Community Events')),
                  ),
                  for (var evento in eventosNotificaciones['communityEvents'])
                    for (var eventoEvento in evento['events'])
                      CustomCardEvents(
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

class ListCardEvents extends StatefulWidget {
  final Map<String, dynamic> event;
  const ListCardEvents(this.event, {Key? key}) : super(key: key);

  @override
  State<ListCardEvents> createState() => _ListCardEventsState();
}

class _ListCardEventsState extends State<ListCardEvents> {
  @override
  Widget build(BuildContext context) {



    return Container(
      height: widget.event['events'].length * 100.0, // Eri es aqui el problema
      width: double.infinity,
      color: Colors.amber,
      child: Column(
        children: [
          Text(widget.event['label']),
          for (var eventoEvento in widget.event['events'])
            CustomCardEvents(
              dateTimeFrom: eventoEvento['dateTimeFrom'],
              dateTimeUntil: eventoEvento['dateTimeUntil'],
              title: eventoEvento['title'],
              isUserEvents: eventoEvento['isUserEvents'],
              icon: eventoEvento['icon'],
              link: eventoEvento['link'],
              notification: eventoEvento['notification'],
              description: eventoEvento['description'],
            ),
        ],
      ),
    );
  }
}
