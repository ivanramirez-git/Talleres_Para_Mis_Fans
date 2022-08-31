import 'package:flutter/material.dart';

Map<String, dynamic> getEventos() {
  Map datesNotifications = {};
  // until = DateTime.now()
  // from = until - 1 year
  // skipDate = until
  datesNotifications['until'] = DateTime.now();
  datesNotifications['from'] =
      datesNotifications['until']!.subtract(const Duration(days: 365));
  datesNotifications['skipDate'] = datesNotifications['until']!;
  print('{\n'
      '  "until": ${datesNotifications['until']!.toIso8601String()},\n'
      '  "from": ${datesNotifications['from']!.toIso8601String()},\n'
      '  "skipDate": ${datesNotifications['skipDate']!.toIso8601String()}\n'
      '}');
  /*
  Event:
    final DateTime dateTimeFrom;
    final DateTime dateTimeUntil;
    final String title;
    final bool isUserEvents;
    final IconData icon;
    final Map<String, String> link;
    final String notification;
    final String description;
  Notification: 
    final DateTime dateTime;
    final String title;
    final bool isRead;
    final IconData icon;
  */
  // Mapa de notificaciones
  Map notifications = {};
  Map events = {};
  // Lista de notificaciones
  List notificationsList = [];
  // Lista de eventos
  List eventsList = [];

  notifications = {
    'dateTime': DateTime.now(),
    'title': 'Notificación 1',
    'isRead': true,
    'icon': const IconData(0xe900, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime': DateTime.now().subtract(const Duration(days: 1)),
    'title': 'Notificación 2',
    'isRead': false,
    'icon': const IconData(0xe800, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime': DateTime.now().subtract(const Duration(days: 2, hours: 15)),
    'title': 'Notificación 3',
    'isRead': true,
    'icon': const IconData(0xe700, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime':
        DateTime.now().subtract(const Duration(days: 3, hours: 5, minutes: 30)),
    'title': 'Notificación 4',
    'isRead': false,
    'icon': const IconData(0xe600, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime':
        DateTime.now().subtract(const Duration(days: 4, hours: 1, minutes: 30)),
    'title': 'Notificación 5',
    'isRead': true,
    'icon': const IconData(0xe500, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime':
        DateTime.now().subtract(const Duration(days: 5, hours: 1, minutes: 30)),
    'title': 'Notificación 6',
    'isRead': false,
    'icon': const IconData(0xe300, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime':
        DateTime.now().subtract(const Duration(days: 6, hours: 1, minutes: 30)),
    'title': 'Notificación 7',
    'isRead': true,
    'icon': const IconData(0xe200, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);
  notifications = {
    'dateTime':
        DateTime.now().subtract(const Duration(days: 7, hours: 1, minutes: 30)),
    'title': 'Notificación 8',
    'isRead': false,
    'icon': const IconData(0xe100, fontFamily: 'MaterialIcons'),
  };
  notificationsList.add(notifications);

  DateTime ramdomDateTime = DateTime.now();
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 2)),
    'title': 'Evento 1',
    'isUserEvents': true,
    'icon': const IconData(0xe900, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.google.com',
      'text': 'Ir a Google',
    },
    'notification': 'Notificación de evento 1',
    'description': 'Descripción de evento 1',
  };
  eventsList.add(events);
  ramdomDateTime = DateTime.now().subtract(const Duration(days: 1));
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 1)),
    'title': 'Evento 2',
    'isUserEvents': false,
    'icon': const IconData(0xe800, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.facebook.com',
      'text': 'Ir a Facebook',
    },
    'notification': 'Notificación de evento 2',
    'description': 'Descripción de evento 2',
  };
  eventsList.add(events);
  ramdomDateTime = DateTime.now().subtract(const Duration(days: 2, hours: 15));
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 1)),
    'title': 'Evento 3',
    'isUserEvents': true,
    'icon': const IconData(0xe700, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.instagram.com',
      'text': 'Ir a Instagram',
    },
    'notification': 'Notificación de evento 3',
    'description': 'Descripción de evento 3',
  };
  eventsList.add(events);
  ramdomDateTime =
      DateTime.now().subtract(const Duration(days: 3, hours: 5, minutes: 30));
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 2)),
    'title': 'Evento 4',
    'isUserEvents': true,
    'icon': const IconData(0xe600, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.twitter.com',
      'text': 'Ir a Twitter',
    },
    'notification': 'Notificación de evento 4',
    'description': 'Descripción de evento 4',
  };
  eventsList.add(events);
  ramdomDateTime =
      DateTime.now().subtract(const Duration(hours: 1, minutes: 30));
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 2)),
    'title': 'Evento 5',
    'isUserEvents': false,
    'icon': const IconData(0xe500, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.youtube.com',
      'text': 'Ir a Youtube',
    },
    'notification': 'Notificación de evento 5',
    'description': 'Descripción de evento 5',
  };
  eventsList.add(events);
  events = {
    'dateTimeUntil': ramdomDateTime,
    'dateTimeFrom': ramdomDateTime.subtract(const Duration(hours: 3)),
    'title': 'Evento 6',
    'isUserEvents': false,
    'icon': const IconData(0xe300, fontFamily: 'MaterialIcons'),
    'link': {
      'url': 'https://www.espn.com',
      'text': 'Ir a Espn',
    },
    'notification': 'Notificación de evento 5',
    'description': 'Descripción de evento 5',
  };
  eventsList.add(events);

  // agrupar e imprimir las listas
  var eventos = getUserEvents(eventsList);
  // ordenar notificaciones por fecha decendente
  notificationsList.sort((a, b) => b['dateTime'].compareTo(a['dateTime']));

  eventos['notifications'] = (notificationsList);

  return eventos;
}

getMonths() {
  return [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December',
  ];
}

// funcion que recibe una lista de eventos y devuelve dos listas, una de eventos de usuario y una de eventos de la comunidad
Map<String, dynamic> getUserEvents(List events) {
  List communityEventsDays = [];
  List userEventsDays = [];
  // agrupar los eventos por dia
  for (var i = 0; i < events.length; i++) {
    var event = events[i];
    var date = event['dateTimeFrom'];
    var day = date.day;
    var month = date.month;
    var year = date.year;
    var label = '${getMonths()[month - 1]} ${day}, ${year}';
    var eventsAux = [];

    if (event['isUserEvents']) {
      bool isSameDay = false;
      for (var j = 0; j < userEventsDays.length; j++) {
        if (userEventsDays[j]['label'] == label) {
          isSameDay = true;
          break;
        }
      }
      if (isSameDay) {
        userEventsDays.forEach((element) {
          if (element['label'] == label) {
            element['events'].add(event);
          }
        });
      } else {
        eventsAux.add(event);
        userEventsDays.add({
          'date': date,
          'label': label,
          'events': eventsAux,
        });
      }
    } else {
      bool isSameDay = false;
      for (var j = 0; j < communityEventsDays.length; j++) {
        if (communityEventsDays[j]['label'] == label) {
          isSameDay = true;
          break;
        }
      }
      if (isSameDay) {
        communityEventsDays.forEach((element) {
          if (element['label'] == label) {
            element['events'].add(event);
          }
        });
      } else {
        eventsAux.add(event);
        communityEventsDays.add({
          'date': date,
          'label': label,
          'events': eventsAux,
        });
      }
    }
  }

  // ordenar las listas por fecha
  communityEventsDays.sort((b, a) {
    return a['date'].compareTo(b['date']);
  });
  userEventsDays.sort((b, a) {
    return a['date'].compareTo(b['date']);
  });
  // devolver las listas
  return {
    'communityEvents': communityEventsDays,
    'userEvents': userEventsDays,
  };
}
