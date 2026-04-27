(function (Drupal) {
  Drupal.behaviors.agModal = {
    attach(context) {
      const modals = context.querySelectorAll('.ag-modal');
      modals.forEach((modal) => {
        if (modal.dataset.agModalInit) {
          return;
        }
        modal.dataset.agModalInit = 'true';
        const overlay = modal.querySelector('.ag-modal__overlay');
        if (overlay) {
          overlay.addEventListener('click', () => {
            modal.hidden = true;
          });
        }
      });
    }
  };
})(Drupal);
