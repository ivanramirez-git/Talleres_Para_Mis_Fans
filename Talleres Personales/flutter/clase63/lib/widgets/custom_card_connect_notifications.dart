import 'package:clase63/data/datos_notifications.dart';
import 'package:flutter/material.dart';

class CustomCardConnectNotifications extends StatelessWidget {
  final DateTime dateTime;
  final String title;
  final bool isRead;
  final IconData icon;

  const CustomCardConnectNotifications({
    Key? key,
    required this.dateTime,
    required this.title,
    required this.isRead,
    required this.icon,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    var months = getMonths();
    return Card(
      child: ListTile(
        leading: Icon(icon),
        title: Text(title),
        subtitle: Text(() {
          final DateTime now = dateTime;
          String month = months[now.month - 1];
          String day = now.day.toString();
          String year = now.year.toString();
          String hour = now.hour.toString();
          String minute = now.minute.toString();
          String ampm = now.hour > 12 ? 'pm' : 'am';
          if (month.length == 1) {
            month = '0$month';
          }
          if (day.length == 1) {
            day = '0$day';
          }
          if (hour.length == 1) {
            hour = '0$hour';
          }
          if (minute.length == 1) {
            minute = '0$minute';
          }
          return '$month $day, $year - $hour:$minute $ampm';
        }()),
        trailing: isRead
            ? Container(
                width: 10,
                height: 10,
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(5),
                  color: Colors.blue,
                ),
              )
            : null,
      ),
    );
  }
}
