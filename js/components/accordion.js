(function (Drupal) {
  Drupal.behaviors.agAccordion = {
    attach(context) {
      const accordions = context.querySelectorAll('.ag-accordion');
      accordions.forEach((accordion) => {
        accordion.querySelectorAll('.ag-accordion__title').forEach((button) => {
          if (button.dataset.agAccordionInit) {
            return;
          }
          button.dataset.agAccordionInit = 'true';
          button.addEventListener('click', () => {
            const content = button.nextElementSibling;
            if (content) {
              content.hidden = !content.hidden;
            }
          });
        });
      });
    }
  };
})(Drupal);
