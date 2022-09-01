import 'package:clase63/widgets/widgets.dart';
import 'package:flutter/material.dart';

class ListCardsEvents extends StatefulWidget {
  final Map<String, dynamic> event;
  const ListCardsEvents(this.event, {Key? key}) : super(key: key);

  @override
  State<ListCardsEvents> createState() => _ListCardsEventsState();
}

class _ListCardsEventsState extends State<ListCardsEvents> {
  double getSizeHeight() {
    return 0.0 + (30 + (widget.event['events'].length * 75.0 + varSize));
  }

  void setVarSize(double value) {
    setState(() {
      varSize += value;
    });
  }

  double varSize = 0;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: getSizeHeight(), // Eri es aqui el problema
      width: double.infinity,
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
                onTap: setVarSize),
        ],
      ),
    );
  }
}
